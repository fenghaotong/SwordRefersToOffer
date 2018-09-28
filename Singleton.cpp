/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//  ���ߣ��κ���
//  C++
//==================================================================

// ������2��ʵ��Singletonģʽ
// ��Ŀ�����һ���࣬����ֻ�����ɸ����һ��ʵ��

//ע�⵽ʵ����m_pInstance��GetInstance���Ǿ�̬�ģ�����û�д���������Ѿ������ˡ�ͨ������GetInstance���������߻�ȡΨһ�Ķ���
#include<iostream>

using namespace std;

template<class T>
class CSingleton {
private:
	CSingleton() {}                    //1.���캯����˽�еģ�����ͨ�����캯�����������ʵ��
	static CSingleton<T> *m_pIstance;     //2.��̬��Ա����������˽�еģ�ָ��һ��CSingletonʵ����ͬһʱ��ֻ����һ���������������ֻ�ܴ���һ��CSingleton��ʵ��
public:
	static CSingleton<T> *GetInstace() {  //3.ֻ��ͨ��������������������һ��CSingletonʵ���������ʵ����Ψһ�ģ���Ϊû������;������CSingletonʵ�������캯����˽�еģ�
		if (m_pIstance == NULL) {
			m_pIstance = new CSingleton<T>;
		}

		return m_pIstance;
	}
};

template<class T>
CSingleton<T> *CSingleton<T>::m_pIstance = NULL:   //4.��ʼ����ľ�̬��Ա����  