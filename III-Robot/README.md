

## 外设分配

| 外设名称 |    对应引脚     |        说明        |
| :------: | :-------------: | :----------------: |
|  USART1  |   PB14, PB15    |      通信串口      |
|  USART2  |    PD5, PD6     |  电源检测 INA226   |
|  USART3  |   PB10, PB11    |      调试串口      |
|  USART4  |    PG14, PG9    |   IMU姿态传感器    |
|          |                 |                    |
|   TIM1   |     PA8,PA9     |    右下轮编码器    |
|   TIM2   |    PA15,PB3     |    右上轮编码器    |
|   TIM3   |     PC6,PC7     |    左下轮编码器    |
|   TIM5   |    PH10,PH11    |    左上轮编码器    |
|   TIM8   | PI2,PI5,PI6,PI7 | 四个L298N的PWM输入 |
|          |                 |                    |





## 协议

|  字节  |   类型    |              可选值              | 说明 |
| :----: | :-------: | :------------------------------: | ---- |
| byte0  |   帧头    |               0xAA               |      |
| byte1  |   帧头    |               0x55               |      |
| byte2  | 设备地址  |            0x01-0xFF             |      |
| byte3  |  帧类型   | 0x00: PC->Robot; 0x01: Robot->PC |      |
| byte4  | 命令类型  |       不同设备对应不同指令       |      |
| byte5  |   帧长    |         用户数据实际长度         |      |
| byte6  | 用户数据0 |                                  |      |
| byte7  | 用户数据1 |                                  |      |
| byte8  | 用户数据2 |                                  |      |
| byte9  | 用户数据3 |                                  |      |
| byte10 |  校验和   |        前10项和对255取余         |      |
| byte11 |   帧尾    |               0xDD               |      |



### 设备地址

| 地址 |   设备   |
| :--: | :------: |
| 0x01 |  机器人  |
| 0x02 | 吊舱云台 |
| 0x03 |  机械臂  |
| 0x04 |   电源   |

### 命令类型

#### 机器人(0x01)

| 命令类型 |      用户数据       |    说明    |
| :------: | :-----------------: | :--------: |
|   0x00   | 0x00,0x00,0x00,0x00 |    停止    |
|   0x01   | 0x00,0x00,0x00,0x00 |    前进    |
|   0x02   | 0x00,0x00,0x00,0x00 |    后退    |
|   0x03   | 0x00,0x00,0x00,0x00 |    右转    |
|   0x04   | 0x00,0x00,0x00,0x00 |    左转    |
|   0x05   | 0x00,0x00,0x00,0x00 |   左平移   |
|   0x06   | 0x00,0x00,0x00,0x00 |   右平移   |
|   0x07   | 0x00,0x00,0x00,0x00 | 原地右旋转 |
|   0x08   | 0x00,0x00,0x00,0x00 | 原地左旋转 |
|          |                     |            |
|          |                     |            |
|   0xFF   | 0x00,0x00,0x00,0x00 |    握手    |

**示例**

停止：`AA 55 01 00 00 00 00 00 00 00 01 DD `



**C#串口发送**

```C++
using System.IO.Ports;

class Program {
    static void Main(string[] args) {
        byte[] buf = {0xaa, 0x55, 0x01, 0x01, 0x00, 0x04, 0x05, 0x06, 0x08, 0x09, 0x05, 0xdd};
        string portName = "COM1";            // 设置端口名
        int baudRate = 9600;                 // 设置波特率
        Parity parity = Parity.None;         // 设置奇偶校验位
        int dataBits = 8;                    // 设置数据位
        StopBits stopBits = StopBits.One;    // 设置停止位

        using (SerialPort serialPort = new SerialPort(portName, baudRate, parity, dataBits, stopBits)) {
            try {
                serialPort.Open();  // 打开串口
                serialPort.Write(buf, 0, buf.Length);  // 发送数据
                Console.WriteLine("Data sent successfully.");
            } catch (Exception ex) {
                Console.WriteLine("Error: " + ex.Message);
            } finally {
                serialPort.Close(); // 关闭串口
            }
        }
    }
}
```









