服务器程序项目（web项目在服务器程序的web_code目录下）：**https://github.com/td1336065617/DataStructPlayground_Server**

测评机项目：**https://github.com/td1336065617/judging**

数据库文件：**https://github.com/td1336065617/DataStructPlayground_Server_sql**

***\*平台部署所需设备\****

Ubuntu22.04服务器（2核4G以上）至少一台

TDSQL-C MySQL数据库一台

***\*平台所需系统环境\****

***\*服务器所需硬件与系统:\****

Ubuntu22.04服务器，因需要运行clion，请保证2核4G以上。

请保证Ubuntu22.04的软件源可用，并且更新软件源列表以及软件包为最新版。平台开发过程中使用的中科大源，因此建议换源为中科大的软件源。

（请保证版本正确，因平台涉及系统调用以及第三方库，无法保证其他版本，可以正常部署运行。）

***\*服务器所需环境配置说明:\****

安装gcc、g++、make

sudo apt install gcc

sudo apt install g++

sudo apt install make

然后在clion官网下载并安装clion（本项目开发所用版本为2023.3.2版本）

下载压缩包情况下

解压

然后以root权限从bin子目录运行CLion.sh

如果没有激活码请选择30天试用

（项目开发期间激活方式为学生邮箱激活）

接下来建议Plugins 安装汉化插件

然后打开DataStructPlayground_Server 和judging两个在程序源码下的项目。（打开项目时候建议选择信任项目）

前者为服务器端程序项目 

后者为判题程序项目 

web前端项目在服务器端程序的web_code/oj下

 

这时候还无法编译运行项目，接下来开始安装依赖。

 

安装libcrypto++

sudo apt install libcrypto++-dev

 

安装curl

apt-get purge libcurl4

sudo apt  install curl

sudo apt-get install libcurl4-openssl-dev

 

安装MySQL库与依赖

sudo apt-get install libmysqlclient-dev

 

安装nlohmann/json

sudo apt-get install nlohmann-json3-dev

 

依赖安装完成

***\*数据库配置说明\****

打开TDSQL-C for MySQL的DMC数据管理控制台，新建数据库DataStructPlayground_Data默认utf8，然后点击导入导出，选择导入数据，数据库选择DataStructPlayground_Data，文件类型SQL，编码utf8。将DataStructPlayground_Data.sql文件导入。

***\*判题程序配置说明\****

judging为判题程序项目

首先删除项目内的 cmake-build-debug文件夹，然后右键项目名（项目目录中的judging）重新加载CMake项目。

如果点击运行后，提示编辑配置。打开编辑配置后，点击左上角加号添加新配置，Cmake应用程序，和Cmake调试。然后应用，确定。

1.数据库信息配置

在main.cpp文件内，具体参考服务器端的数据库信息配置

 

2.判题程序HTTP服务器信息设置。

epoll.set_server("127.0.0.1",post,"127.0.0.1:9999/Feedback_of_the_judgment.jk",1);

第一个信息为判题程序的HTTP服务器ip，第二个为端口，第三个为服务器程序的链接地址，后面接口固定，请修改前面的IP地址与端口部分与服务器程序的配置保持一致。第四个为判题程序的标识，请和服务端的src/judging_list文件内的顺序对应，从1开始。

post为运行后在终端输入。

3.题目多组数据部署

因考虑到系统压力题目录入界面web只支持单组小规模数据录入，如果题目需要多组大规模数据，请直接部署在测评程序的src\judging_data\题目编号下文件名参考1.in/1.out（x.in/x.out）,.in为标准输入数据文件.out为标准输出数据文件。

 

***\*服务器程序配置说明\****

DataStructPlayground_Server为服务器程序项目

首先删除项目内的 cmake-build-debug文件夹，然后右键项目名（项目目录中的DataStructPlayground）重新加载CMake项目。

如果点击运行后，提示编辑配置。打开编辑配置后，点击左上角加号添加新配置，Cmake应用程序，和Cmake调试。然后应用，确定。

1.数据库信息

main.cpp文件内epoll.setmysql的参数依次为

链接（host）、端口（port）、用户名（username）、密码（password）、数据库名（database_name），数据库连接池最低维持链接数、数据库连接池最大链接数。（后两个可以维持原样）

 

2.线程池信息

 main.cpp文件内epoll.set_Thread_Poll(100,5,10);

第一个值为最大线程数 第二个为最小维持数 第三个为裁员等待时间（秒）

建议第一个为机器最大线程数 

第二个数值为机器线程数的一半 

建议第三个数值不要动

 

3.HTTP服务器信息设置

main.cpp文件内epoll.set_server("127.0.0.1",9999);

第一个为ip地址 第二个为使用端口

第一个设置为0.0.0.0即为公网ip

 

4.服务器与判题机对接信息设置

项目内src/judging_list文件内设置测评机信息

两行为一组，可为多组，每组之间无需多余回车。

第一行为测评机的地址 第二行为测评机的性能参数

例如只有一台测评机即为

127.0.0.1:5702/judging_problem.jk

1

两台即为

127.0.0.1:5702/judging_problem.jk

1

127.0.0.1:5703/judging_problem.jk

1

目前只需要考虑第一行参数即可 第二行设置为1即可

***\*注意：服务器程序在初始化阶段会读入这个文件内的数据，所以请确保文件内的判题机运行状态正常，真实存在。\****

 

5.忘记密码功能发送邮件信息设置

请修改 Web_Task/Forgot_password.cpp 内Smtp smtp（）按照以下注释配置邮箱smtp信息，请配置前四项，确保可以正确发送邮件。

Smtp smtp(

25,/*smtp端口*/

"smtp.163.com",/*smtp服务器地址*/

"13766949653@163.com",/*你的邮箱地址*/

"********************",    /*邮箱密码*/

email,/*目的邮箱地址*/

"DataStructPlayground忘记密码",/*主题*/

"您的新密码是:"+ password/*邮件内容*/														/*邮件正文*/

);
