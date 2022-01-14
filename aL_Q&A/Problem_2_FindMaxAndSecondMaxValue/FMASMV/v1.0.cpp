// �������ǲ������ֵ-->���ҡ����ֵ
// �ؼ���-->�����ֵһ���������ֱֵ�ӱȽϹ���
#include<iostream>
using namespace std;
// ��ȡ����,���غ�������ֵ������
double* getInput();

// �������ֵ������ֵ
// 1. ���������ķ�ʽ����ÿ��ֵ��������ֵ����������Ƚ�
// pros: ���Ա�֤����һ���õ���һ������Ϊ�������������
// cons: ʱ�临�ӶȽϸ�
// 1.1 ���β���
double* ByBruteForceSearch_1(double* inputs);
// 1.2 һ�β���
double* ByBruteFOrceSearch_2(double* inputs);

// 2. ð�ݵķ�ʽ��������ǰ���ֵ�뵱ǰ�±�ֵ�Ƚ�
// 2.1 һ�β���
double* ByBubbleSearch_1(double* inputs);

// 3. ���ֵķ�ʽ�������򣬹����ȶ���������ȷ�������δ�ֵ��
// pros: �������������ϴ�ķ�ʽ������ʱ�临�ӶȽϵ�
// cons: һ����ȫ���ҿ��Եó����ֵ������һ������ȷ�������ֵ�����Ի��һ���п����Ǵ����ֵ���б�
// �Ƕ��ַ�Ҳ��ʵ��Ϊ����ѵķ���
// ��ʱ����
double* ByBinarySearch_1(double* inputs);

// 4. ����ѵķ���

// ��ȡ���,չʾ����������
double* putRes(double* res, const char* mode);

int main() {
	double* inputs = nullptr;
	do {
		inputs = getInput();
	} while (inputs == nullptr);
	double* output_1 = ByBruteFOrceSearch_2(inputs);
	double* output_2 = ByBubbleSearch_1(inputs);
	double* output_3 = ByBinarySearch_1(inputs);
	putRes(output_1, "BtuteForceSearch and one echo");
	putRes(output_2, "Bubble Search and one echo");
	putRes(output_3, "Binary Search and one echo");
	return 0;
}
double* getInput() {
	printf("%s\n", "Input the count of numbers you want to find the MAX and Second MAX");
	int n = 0;
	// scanf ���سɹ�����ֵ�ĸ���
	if (1 == scanf_s("%d", &n)) {
		printf("%s\n", " Now input the numbers themselves.");
		if (n >= 1) {
			int LEN = n + 1;
			double* inputs = new double[LEN];
			double tmp = 0.0;
			for (int i = 1; i <= n; i++) {
				if (1 == scanf_s("%lf", &tmp)) {
					inputs[i] = tmp;
				}
			}
			inputs[0] = n;
			printf("%s\n", "Input done. The numbers are as follows.");
			for (int i = 0; i <= n; i++) {
				printf("%lf\n", inputs[i]);
			}
			return inputs;
		}
		printf("%s\n", "Sorry you have input the innappropriate length count of numbers.");
	}
	return nullptr;
}

double* ByBruteForceSearch_1(double* inputs)
{
	return nullptr;
}

double* ByBruteFOrceSearch_2(double* inputs)
{
	return nullptr;
}

double* ByBubbleSearch_1(double* inputs)
{
	if (inputs != nullptr) {
		double MAX = 0.0, sMAX = 0.0;
		for (int i = 1; i <= inputs[0]; i++) {
			if (inputs[i] > MAX) {
				sMAX = MAX;
				MAX = inputs[i];
			}
			else {
				if (inputs[i] > sMAX) {
					sMAX = inputs[i];
				}
			}
		}
		double* res = new double[2];
		res[0] = MAX;
		res[1] = sMAX;
		return res;
	}
	return nullptr;
}

double* ByBinarySearch_1(double* inputs)
{
	return nullptr;
}

double* putRes(double* res, const char* mode)
{
	if (res != nullptr) {
		printf("%s\n", mode);
		printf("%s%lf\n%s%lf", "Max is", res[0], "Second Max is ", res[1]);
	}
	return nullptr;
}




//ps. ��������ʮƥ����Ѱ���ܵ�������ƥ��������Ҫ����������[һ���������ʮƥ��]