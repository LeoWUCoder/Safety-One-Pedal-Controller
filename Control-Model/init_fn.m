function init_fn()
%INIT_FN 初始化车辆纵向动力学模型参数

%% 车辆基本参数
m = 1600;                  % 车辆质量，kg
r = 0.30;                  % 车轮等效半径，m

%% 初始状态
v0_km_h = 0;               % 仿真初始车速，km/h
v0_m_s = v0_km_h / 3.6;    % 积分器初始车速，m/s

%% 车辆速度限制
MAX_SPEED_FORWARD = 240;   % 最大前进速度，km/h
MAX_SPEED_BACKWARD = 60;   % 最大倒车速度的绝对值，km/h

%% 电机和传动系统参数
MAX_TORQUE_REVERSE = 40;   % 最大倒车电机扭矩绝对值，Nm
MAX_TORQUE = 80;           % 最大前进电机扭矩，Nm
TRANSMISSION_RATIO = 12;   % 电机到车轮的总传动比

%% 挡位切换参数
MAX_RDB_ENGAGE_SPEED = 0.5; % R/D/B挡允许接合的最大车速，km/h

%% 空气动力学参数
S = 3.5;                   % 车辆迎风面积，m^2
rho = 1.25;                % 空气密度，kg/m^3
c_x = 0.3;                 % 空气阻力系数，无量纲

%% 阻力模型参数
X_air = 0.5 * S * rho * c_x;
X_tyres = X_air * 50 / 3.6;

%% 将参数写入 MATLAB 基础工作区
assignin('base', 'm', m);
assignin('base', 'r', r);

assignin('base', 'v0_km_h', v0_km_h);
assignin('base', 'v0_m_s', v0_m_s);

assignin('base', 'MAX_SPEED_FORWARD', MAX_SPEED_FORWARD);
assignin('base', 'MAX_SPEED_BACKWARD', MAX_SPEED_BACKWARD);

assignin('base', 'MAX_TORQUE_REVERSE', MAX_TORQUE_REVERSE);
assignin('base', 'MAX_TORQUE', MAX_TORQUE);
assignin('base', 'TRANSMISSION_RATIO', TRANSMISSION_RATIO);

assignin('base', ...
    'MAX_RDB_ENGAGE_SPEED', MAX_RDB_ENGAGE_SPEED);

assignin('base', 'S', S);
assignin('base', 'rho', rho);
assignin('base', 'c_x', c_x);

assignin('base', 'X_air', X_air);
assignin('base', 'X_tyres', X_tyres);

% assignin用于从当前函数或脚本，把变量写入指定的 MATLAB 工作区。
% 基本语法：
% assignin(workspace, variableName, value)

%{
assignin用于从当前函数或脚本，把变量写入指定的 MATLAB 工作区。
基本语法：
assignin(workspace, variableName, value)
参数	类型	含义
workspace	字符串或字符向量	目标工作区，只能是 "base" 或 "caller"
variableName	字符串或字符向量	要创建或覆盖的变量名称
value	任意 MATLAB 数据	写入变量的值
%}
end