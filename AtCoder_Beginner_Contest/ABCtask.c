#include <stdio.h>

long long POW(int a, int b)
{
	int i;
	long long ret = 1;
	for( i=0; i<b; i++)ret *= a;
	return ret;
}

char* decMinus2bin(char* str, int N)
{
	int u,k;
	long long i,j,sum;
	static const long long oddsum[]={
		2LL, 10LL, 42LL,
		170LL, 682LL, 2730LL,
		10922LL, 43690LL, 174762LL,
		699050LL, 2796202LL, 11184810LL,
		44739242LL, 178956970LL, 715827882LL,
		2863311530LL
	};
	static const long long evensum[]={
		1LL, 5LL, 21LL,
		85LL, 341LL, 1365LL,
		5461LL, 21845LL, 87381LL,
		349525LL, 1398101LL, 5592405LL,
		22369621LL, 89478485LL, 357913941LL,
		1431655765LL
	};
	
	if( N<0 )return NULL;
	if( N==0 ){
		str[0] = '0', str[1] = 0;
		return str;
	}
	
	for(u=0; evensum[u] < N; u++);
	j = (1LL<<(2*u));

	sum = j;
	
	do{
		if( sum<N ){
			for(u=0; sum+evensum[u] < N ; u++);
			j = j + (1LL<<(2*u));
		}else if( sum>N ){
			for(u=0; sum-oddsum[u] > N; u++);
			j = j + (1LL<<(2*u+1));
		}
		sum = 0;
		for(i=1,k=0; i<=j; i<<=1,k++){
			if( j&i )
				sum += POW(-2,k);
		}
	}while( sum!=N );
	
	str[k] = 0;
	for(i=1; i<=j; i<<=1){
		str[--k] = j&i ? '1' : '0';
	}
	
	return str;
}

int main()
{
	char str[34];
	int i;
	
	/*** Sample ***/
	for(i=0; i<=100; i++){
		printf("%d : %s\n",i,decMinus2bin(str,i));
	}
	printf("%d : %s\n",-1405737207,decMinus2bin(str,-1405737207));
	printf("%d : %s\n",2147483647,decMinus2bin(str,2147483647));
	/**************/
	
	return 0;
}