function smoothX = FilterEMGData(data,FS,FCH,FCL,WL)
    meanX = data-mean(data);
    dcX = detrend(meanX);
    halfFS = FS/2;
    [b,a] = butter(2,[FCH FCL]/halfFS,"bandpass");
    filtX = filtfilt(b,a,dcX);
    rectX = abs(filtX);
    smoothX = movmean(rectX,WL);
end