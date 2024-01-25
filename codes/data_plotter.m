setpoint = 20; %cm
x = table2array(CustomData20240108Recording1);
l = length(x);
time = 0:0.1:(l-1)*0.1;
plot(time, x)
hold on
plot(time, setpoint*ones(1,l));
grid("on");
title("Distance vs Time");
xlabel("Time(s)");
ylabel("Distance(cm)");