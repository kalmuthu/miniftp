������Ҫʵ�ֵ��Ǻ�ˣ��ͻ��˿�����leapftp3.0

Ŀǰʵ�ֵĹ��ܣ���½У�顢���жϿ������������ơ��ϵ��������ϵ����ء����жϿ�

�õ��ļ�����selectģ�ͳ�ʱ��⣬�����ģ�ʹ����������Ӻ��������ӣ�������ģʽ����NATӰ�죬�Զ���nobody���̺ͷ�����̼�ͨ��Э�飬ALARM�ź�ʵ�ֿ��жϿ�����װwriten/readn���TCPճ����˫ Hash����ip��������������������Hash��ͻ���ڴ�ع����ϣ�ڵ��ڴ档
		
������Ŀ��Ҫ������ģ����ɣ�ftpЭ�����ģ�顢�ڲ�Э�����ģ�顢���̼�ͨ��ģ��
```
tree /f
����ftp
    ����miniftpd.conf						//�����ļ�
    ����.h
    ��      ftpproto.h                   //ftpЭ�����
    ��      hash.h						//��ϣ��
    ��      memorypool.h					//�ڴ��
    ��	   parseconf.h					//���������ļ�
	��      priparent.h					//�ڲ�Э�����
    ��      prisock.h					//�ڲ�����ͨ��
	��      str.h						//�ַ���������װ
	��      sysutil.h					//ϵͳ������װ
	��      tunable.h					//���ò���
    ����.cpp
            ftpproto.cpp            
            hash.cpp        
            memorypool.cpp            
            parseconf.cpp                 
            priparent.cpp
            prisock.cpp          
            str.cpp
            sysutil.cpp                
            tunable.cpp            
            main.cpp
```
```
���ͻ��ˡ�<-------->���û����桿
                         |
                         |
                         |
```