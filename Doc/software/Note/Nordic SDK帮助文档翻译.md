# Scheduler handling library
  �������������ǽ�ִ�����̴��ж�������(Interrupt context)�л���Main������(Main context).

## ��Ҫ������
   - Main�����ģ�
     - Ϊ����Ҫ�������¼�����һ��������(handler);
     - �ڽ�����ѭ��֮ǰ������APP_SCHED_INIT()������ʼ��������;
     - ����ѭ���е���app_sched_execute()����ϵͳ���κ�һ���ȴ��¼��л��Ѻ󣨵��������`sd_app_evt_wait()`�������أ���
  - Interrupt�����ģ�
    - ���жϴ������У�����`app_sched_event_put()`���������¼����뵽�������Ķ����С�`app_sched_execute()`��������Ӷ�����ȡ�����¼�������
    ���ø��¼��Ĵ�������    
    
    ![�������������](./res/SDK/High level design of scheduler.png)

    
