[x, Fs] = audioread ("audioDSP.wav") %% Reads the Audio File
%sound(x)
t = (0: length(x) - 1)/Fs;



Q= fft(x)
mag_Q = abs(Q)
tm=0:1/Fs:(length(Q)-1)/Fs
freq=0:1/tm(end):Fs/2-(1/tm(end))
figure(1)
plot(freq,mag_Q(1:length(freq)))

%low pass filter at break freq = 2000 Hz
[b,a] = butter(6,2000/(Fs/2),'low');
H = freqz(b,a,'whole',Fs)
mag_H = abs(H)
tm=0:1/Fs:(length(H)-1)/Fs
freq=0:1/tm(end):Fs/2-(1/tm(end))
figure(2)
plot(freq,mag_H(1:length(freq)))
h1_t = ifft(H, Fs) 

%band stop filter at break freq = 799 - 801 Hz
[b2,a2] = butter(3,[799/(Fs/2) 801/(Fs/2)],'stop');
H2 = freqz(b2,a2,'whole',Fs)
mag_H2 = abs(H2)
tm=0:1/Fs:(length(H2)-1)/Fs
freq=0:1/tm(end):Fs/2-(1/tm(end))
figure(3)
plot(freq,mag_H2(1:length(freq)))
title('Bandstop filter at \omegal=799 rad and \omegah=801 rad');
xlabel('\omega (rad)');
ylabel('Magnitude');
h2_t = ifft(H2, Fs)

h_t = conv(h1_t,h2_t)
x_filtered = conv(x,h_t)

audiowrite ('Clean.wav',x_filtered,Fs);
[x_audio, Fs] = audioread("Clean.wav")
sound(x_audio)

y_filtered = fft(x_audio); %% Implements DFT to convert time domain to frequency domain
Yabs = abs(y_filtered);
Yabshift = abs(fftshift(fft(x_audio)))


Qnew = fft(x_audio)
mag_Qnew = abs(Qnew)
tm=0:1/Fs:(length(Qnew)-1)/Fs
freq=0:1/tm(end):Fs/2-(1/tm(end))
figure(4)
plot(freq,mag_Qnew(1:length(freq)))

[D, T, R] = audioread('audioDSP.Wav');
F = D(:,4);                 % Data Channel
Ts = 2E-4;                  % Sampling Interval (s)
Fs = 1/Ts;                  % Sampling Frequency (Hz)
Fn = Fs/2;                  % Nyquist Frequency
F(isnan(F))=[];             % Eliminate ‘NaN’ Values First
LF = size(F,1);             % Length of Data Vector
T = linspace(0,1,LF)*Ts;    % Create Time Vector
figure(1)                   % Plot Data 
plot(T, F)
grid

n = 5000;
[x,fs]=audioread('audioDSP.Wav');
idx = 1:n;
subset = x(idx,:);
t = (idx-1)./fs;
plot(t,subset)
xlabel('time')
ylabel('x[n]')