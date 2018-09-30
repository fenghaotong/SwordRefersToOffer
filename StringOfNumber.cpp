/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.28
*
* ������20: ��ʾ��ֵ���ַ���
* ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
* �ַ�����+100������5e2������-123������3.1416������-1E-16������ʾ��ֵ������12e����
* ��1a3.14������1.2.3������+-5������12e+5.4��������
*******************************************************************/

class Solution {
public:
	bool scanUnsignedInteger(const char** str);
	bool scanInteger(const char** str);

	// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
	// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
	bool isNumeric(const char* str){
		if (str == nullptr)
			return false;

		bool numeric = scanInteger(&str);

		// �������'.'�������������ֵ�С������
		if (*str == '.'){
			++str;
			// ����һ�д�����||��ԭ��
			// 1. С������û���������֣�����.123����0.123��
			// 2. С����������û�����֣�����233.����233.0��
			// 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
			numeric = scanUnsignedInteger(&str) || numeric;
		}

		// �������'e'����'E'�����������ŵ������ֵ�ָ������
		if (*str == 'e' || *str == 'E'){
			++str;
			// ����һ�д�����&&��ԭ��
			// 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
			// 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
			numeric = numeric && scanInteger(&str);
		}

		return numeric && *str == '\0';
	}

	bool scanUnsignedInteger(const char** str){
		const char* before = *str;
		while (**str != '\0' && **str >= '0' && **str <= '9')
			++(*str);
		// ��str�д�������0-9������ʱ������true
		return *str > before;
	}

	// �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
	bool scanInteger(const char** str){
		if (**str == '+' || **str == '-')
			++(*str);
		return scanUnsignedInteger(str);
	}
};