// Good Numbers
//coding ninjas

bool is_good(int k,int sum,int digit)
{
	if(k==0)
	{
		return true;
	}
	int last=k%10;
	if(last<=sum||last==digit){
		return false;
	}
	else{
		return is_good(k/10,sum+last,digit);
	}
}
vector<int> goodNumbers(int a, int b, int digit) {
	// Write your code here.
	vector<int>ans;
	for(int i=a;i<=b;i++)
	{
		if(i%10==digit)
		{
			continue;
		}
		int sum=i%10;
		if(is_good(i/10,sum,digit))
		{
			ans.push_back(i);
		}
	}
	return ans;
}
