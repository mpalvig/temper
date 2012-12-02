%% load data

data = load('elkedel.dat');
data = data(1:end-3,:);

sec = data(:,1) - min(data(:,1));
minutes = sec/60;
hours = minutes/60;
temp = data(:,2);

%% plot

figure(1)
plot(sec(1:60),temp(1:60));
ylabel('Temperature [^o C]')
xlabel('Time [seconds]')
grid on

figure(2)
plot(minutes(1:10*30),temp(1:10*30));
ylabel('Temperature [^o C]')
xlabel('Time [minutes]')
grid on

figure(3)
plot(hours,temp)
ylabel('Temperature [^o C]')
xlabel('Time [hours]')
grid on
