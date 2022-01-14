// 本质上是查找最大值-->查找、最大值
// 关键是-->次最大值一定是与最大值直接比较过的
#include<iostream>
using namespace std;
// 获取输入,返回含有所有值的数组
double* getInput();

// 查找最大值与次最大值
// 1. 暴力搜索的方式，对每个值都与其他值进行搜索与比较
// pros: 可以保证遍历一遍后得到的一组数即为最大数与次最大数
// cons: 时间复杂度较高
// 1.1 两次查找
double* ByBruteForceSearch_1(double* inputs);
// 1.2 一次查找
double* ByBruteFOrceSearch_2(double* inputs);

// 2. 冒泡的方式，仅将当前最大值与当前下标值比较
// 2.1 一次查找
double* ByBubbleSearch_1(double* inputs);

// 3. 二分的方式【须有序，故须先二分排序再确定最大与次大值】
// pros: 适用于数据量较大的方式，因其时间复杂度较低
// cons: 一次完全查找可以得出最大值，但不一定可以确定次最大值【可以获得一个有可能是次最大值的列表】
// 非二分法也，实则为大根堆的方法
// 暂时搁置
double* ByBinarySearch_1(double* inputs);

// 4. 大根堆的方法

// 获取结果,展示到命令行中
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
	// scanf 返回成功被赋值的个数
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




//ps. 类似与四十匹马中寻找跑的最快的四匹马，最少需要几场比赛？[一场比赛最多十匹马]