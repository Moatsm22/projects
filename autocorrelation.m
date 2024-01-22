clc;
clear;
close all;

fs=10000;
recorder - audiorecorder (fs,8,1);
disp('Start recording');
recordblocking (recorder, 5);
disp('End of recording');
play back
play (recorder);
store
y-getaudiodata (recorder);
filename='speech.wav';
audiowrite('speech.wav', y, 10000);
audioinfo (filename);
audioread('speech.wav');
info
disp (info);
[y, fs]
figure (1);
plot (y);
title('Amplitude plot of spoken word');
xlabel('amplitude');
ylabel('sample number');
grid on;
pause;

sum = zeros (1,320);
for k=320
sum (k)=0;
end
for k=1:320
    for i=1:32
    sum (k)=sum (k) + (a (i)*a (i+k));
    sum (k)=sum (k)/32;
    end

subplot (2, 1, 2);
plot (sum);
title ('plot of correlationof a signal');
xlabel('sample no');
ylabel('correlation');
grid on:
[pks, locs] findpeaks (sum);
min (fs./diff (locs)), mean (fs./diff (locs)), max (fs./diff(locs));
disp (locs);
[mm, peakl_ind] min ((fs./diff (locs)));
period-locs (peakl_ind+1)-locs (peakl_ind); %comparing the "time" between peaks
pitch Hz fs/period;
disp (pitch Hz);
end

%save ('filename','variable Name');