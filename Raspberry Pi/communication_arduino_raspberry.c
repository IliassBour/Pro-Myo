#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>

//Le temps d'execution pour 1000 donnees est d'environ 4.3 secondes. Donc 0.0043 secondes par donnee
#define BAUDRATE B115200
//verifier le port utiliser par le arduino avant sur le terminal avec : ls /dev/tty*
#define MODEMDEVICE "/dev/ttyACM0"
#define MODEMDEVICE2 "/dev/ttyACM1"
#define PI 3.14159265358979323846

int open_port() {
	int serial_port = open(MODEMDEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK);
	
	if(serial_port < 0) {
		printf("Can't open port %s \n", MODEMDEVICE);
		serial_port = open(MODEMDEVICE2, O_RDWR | O_NOCTTY | O_NONBLOCK);
	}
	if(serial_port < 0) {
		printf("Can't open port %s \n", MODEMDEVICE2);
		return -1;
	}
	fcntl(serial_port, F_SETFL, 0);
	return serial_port;
}

struct termios set_communication(int serial_port, struct termios oldtio, struct termios newtio) {
	tcgetattr(serial_port, &oldtio);	
	bzero(&newtio, sizeof(newtio));
	
	//configure communication
	newtio.c_cflag &= ~PARENB | PARODD;
	newtio.c_cflag &= ~CSTOPB;
	newtio.c_cflag &= ~CSIZE;
	newtio.c_cflag |= CS8;
	newtio.c_cflag &= ~CRTSCTS;
	newtio.c_cflag |= CREAD | CLOCAL;
	
	newtio.c_lflag &= ~ICANON;
	newtio.c_lflag &= ~ECHO;
	newtio.c_lflag &= ~ECHOE;
	newtio.c_lflag &= ~ECHONL;
	newtio.c_lflag &= ISIG;
	newtio.c_iflag &= ~(IXON | IXOFF | IXANY);
	newtio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | IGNCR | ICRNL);
	
	newtio.c_oflag &= ~OPOST & ~ONLCR;
	
	newtio.c_cc[VMIN] = 0;
	newtio.c_cc[VTIME] = 1;
	newtio.c_cc[VEOL] = 0x0;
	newtio.c_cc[VEOF] = 0x0;
	
	cfsetispeed(&newtio, BAUDRATE);
	cfsetospeed(&newtio, BAUDRATE);

	tcflush(serial_port, TCIFLUSH);
	tcsetattr(serial_port, TCSANOW, &newtio);
	
	return oldtio;
}

void close_communication(int serial_port, struct termios oldtio) {
	tcsetattr(serial_port, TCSANOW, &oldtio);
	close(serial_port);
}

void read_port(int serial_port, double *capt_emg, double *capt_pressure) {
	char read_buf[255] = { 0 };
	int index = -1;
	
	read(serial_port, &read_buf, sizeof(read_buf));
	printf("Data : %s \n", read_buf);
	*capt_emg = atof(read_buf);
	for(int i = 0; i < 255; i++) {
		if(index > -1) {
			read_buf[i-index] = read_buf[i];
		}
		else if(read_buf[i] == '\n') {
			index = i+1;
		}
	}
	*capt_pressure = atof(read_buf);
}

void write_port(int serial_port, int comand) {
	char write_buf[4] = { 0 };
	sprintf(write_buf, "%3d", comand);
	write_buf[3] = '\n';
	
	printf("Comande : %.4s", write_buf);
	write(serial_port, write_buf, sizeof(write_buf));
}

void convert_to_volt(double *y, int n, double *volt) {
	for (int i = 0; i < n; i++) {
		volt[i] = (y[i] * 5) / 1024;
	}
}

void butterworth_highpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered) {
    double alpha = tan(PI * cutoff_frequency / sample_rate);
    double a0 = 1 / (1 + alpha);
    double a1 = -a0;
    double b1 = a0 * (1 - alpha);
    double x_prev = y[0];
    double y_prev = x_prev;
    filtered[0] = y_prev;
    for (int i = 1; i < n; i++) {
        double x = y[i];
        double y = a0 * x + a1 * x_prev + b1 * y_prev;
        filtered[i] = y;
        x_prev = x;
        y_prev = y;
    }
}

void butterworth_lowpass(double *y, int n, double cutoff_frequency, double sample_rate, double *filtered) {
    double alpha = tan(PI * cutoff_frequency / sample_rate);
    double a0 = 1 / (1 + alpha);
    double a1 = a0 * alpha;
    double b1 = a0 * (1 - alpha);
    double x_prev = y[0];
    double y_prev = x_prev;
    filtered[0] = y_prev;
    for (int i = 1; i < n; i++) {
        double x = y[i];
        double y = a0 * x + a1 * x_prev + b1 * y_prev;
        filtered[i] = y;
        x_prev = x;
        y_prev = y;
    }
}

void rectify(double *y, int n, double *rectified) {
    for (int i = 0; i < n; i++)
        rectified[i] = fabs(y[i]);
}

void centered_moving_average(double *y, int n, int window_size, double *smoothed) {
    int half_window = window_size / 2;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        int count = 0;
        for (int j = i - half_window; j <= i + half_window; j++) {
            if (j >= 0 && j < n) {
                sum += y[j];
                count++;
            }
        }
        smoothed[i] = sum / count;
    }
}

void amplify(double *y, int n, double *amplified) {
	double factor = 0.1;
	for (int i = 0; i < n; i++)
		amplified[i] = y[i] * factor;
	
}

void filtre(double *input, int nbDataPoints, double *output) {
    double data_volt[nbDataPoints];
    double data_highpass[nbDataPoints]; 
	double data_bandpass[nbDataPoints];
	double rectified[nbDataPoints];
    double smoothed[nbDataPoints];
	double fc_low = 180;
    double fc_high = 65;
    double fs = 1000; //frequence d echantillonnage
    int window_size = 301;
    
    convert_to_volt(input, nbDataPoints, data_volt);    

	//Butterworth
	//maybe didvide by 2 -> fs
    butterworth_highpass(input, nbDataPoints, fc_high , fs/2, data_highpass);
    butterworth_lowpass(data_highpass, nbDataPoints, fc_low, fs/2, data_bandpass);

    //Rectifier
    rectify(data_bandpass, nbDataPoints, rectified);
    //Analyser
    centered_moving_average(rectified, nbDataPoints, window_size, smoothed);
    amplify(smoothed, nbDataPoints, output);
}

void filtre_realtime(double *data_part, double *new_value, int part_step, double *smoth_part) {
	int part_size = 70;
    
    for(int i = 0; i < part_size-part_step; i++) {
		data_part[i] = data_part[i + part_step];
	}
	for(int i = 0; i < part_step; i++) {
		data_part[i+part_size-part_step] = new_value[i];
	}
	filtre(data_part, part_size, smoth_part);
}

void object_threshold(double data, double *threshold) {
	if (*threshold < data)
		*threshold = data;
}

double analyse_threshold(double capt_emg, double capt_pressure, double threshold, double *threshold_move, double threshold_comparaison) {
	double comand;
	if(capt_emg <= *threshold_move) {
		comand = 1;
		*threshold_move = threshold;
	} else if(capt_emg > *threshold_move && capt_pressure < 400) {
		comand = 2;
		*threshold_move = threshold_comparaison;
	} else {
		comand = 3;
		*threshold_move = threshold_comparaison;
	}
	
	return comand;
}

int main() {
	/*---------------------------------
	 Demo
	---------------------------------*/
	printf("Start\n----------------------------------\n");
	struct termios oldtio, newtio;
	int serial_port;
	double capt_emg, capt_pressure;
	double threshold = 170;
	double threshold_move = 170;
	double threshold_comparaison;
	time_t start_time, now;
	float set_time = 5, elapsed_time;
	double temp_emg;

	//open serial port
	serial_port = open_port();
	if(serial_port == -1) {
		return -1;
	}
	
	//set communication between Arduino and Pi
	oldtio = set_communication(serial_port, oldtio, newtio);

	//filter variable
	int first = 1, index = 6;
	double data_part[70] = { 0 };
	double data_filtered[70];
	double new_value[7];
	int part_step = 7;
	FILE* file = fopen("arduino.txt", "a+");
	
	while(1) {
		//Menu
		printf("Make A Choice\n 1- Calibration\n 2- Prise Cynlindrique\n 3- Back\n 4- Count Down\n 5- Prise Pouce Index\n");
		int choice, comand;
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				comand = 1;
				threshold = 0;
				printf("Calibration start");
				write_port(serial_port, comand);
				time(&start_time);
				while(elapsed_time < set_time) {
					read_port(serial_port, &capt_emg, &capt_pressure);
					if(capt_emg == capt_pressure) {
						capt_emg = temp_emg;
					} else {
						temp_emg = capt_emg;
					}
					//printf("Capteur EMG: %f\n", capt_emg);
					
					
					if(first) {
						if(index < 70 - part_step) {
							data_part[index] = capt_emg;
							index++;
						} else {
							new_value[0] = capt_emg;
							index = 1;
							first = 0;
						}
					} else {
						new_value[index] = capt_emg;
						if(index == 6) {
							filtre_realtime(data_part, new_value, part_step, data_filtered);
							for(int i = 0; i < 70; i+=7) {
								object_threshold(data_filtered[i], &threshold);
							}
							index = -1;
						}
						
						index++;
					}
					
					write_port(serial_port, comand);
					
					
					now = time(NULL);
					elapsed_time = difftime(now, start_time);
				}
				elapsed_time = 0;
				first = 1;
				index = 6;
				printf("Calibration done\nSeuil : %f\n", threshold);
				
				break;
			case 2: 
				comand = 2;
				threshold_comparaison = threshold/2;
				printf("Motors Start\n");
				write_port(serial_port, comand);
				while(1) {
					read_port(serial_port, &capt_emg, &capt_pressure);
					//printf("Capteur EMG : %f\n", capt_emg);
					//printf("Capteur pression : %f\n", capt_pressure);
					comand = 0;
					if(first) {
						if(index < 70 - part_step) {
							data_part[index] = capt_emg;
							index++;
						} else {
							new_value[0] = capt_emg;
							index = 1;
							first = 0;
						}
					} else {
						new_value[index] = capt_emg;
						if(index == 6) {
							filtre_realtime(data_part, new_value, part_step, data_filtered);
							comand = analyse_threshold(data_filtered[69], capt_pressure, threshold, &threshold_move, threshold_comparaison);
							fprintf(file, "%f\n", data_filtered[69]);
							index = -1;
						}
						index++;
					}
					write_port(serial_port, comand);
				}
				printf("Motors Done\n");
				
				break;
			case 3: 
				comand = 3;
				printf("Start\n");
				write_port(serial_port, comand);
				sleep(5);
				printf("Done\n");
				
				break;
			case 4: 
				comand = 4;
				printf("Start\n");
				write_port(serial_port, comand);
				sleep(4);
				printf("Done\n");
				
				break;
			case 5: 
				comand = 5;
				threshold_comparaison = threshold/2;
				printf("Motors Start\n");
				write_port(serial_port, comand);
				while(1) {
					read_port(serial_port, &capt_emg, &capt_pressure);
					printf("Capteur EMG : %f\n", capt_emg);
					printf("Capteur pression : %f\n", capt_pressure);
					comand = 0;
					
					if(first) {
						if(index < 70 - part_step) {
							data_part[index] = capt_emg;
							index++;
						} else {
							new_value[0] = capt_emg;
							index = 1;
						}
					} else {
						new_value[index] = capt_emg;
						if(index == 6) {
							filtre_realtime(data_part, new_value, part_step, data_filtered);
							comand = analyse_threshold(data_filtered[69], capt_pressure, threshold, &threshold_move, threshold_comparaison);
							index = -1;
							fprintf(file, "%f\n", data_filtered[69]);
						}
						index++;
					}
					write_port(serial_port, comand);
				}
				printf("Motors Done\n");
				
				break;
			default:
				printf("Please choose a valid option\n");
				break;
		}
	}
	
	close_communication(serial_port, oldtio);
	
	return 0;
}
