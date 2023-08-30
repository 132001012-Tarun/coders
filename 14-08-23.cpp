// The Celebrity Problem



// intution is like first storing each and every element in the stack and checking top two elements with the condition that if one knows another but other don't know then push other
// similarly at last possibility is that there left 0 element at the stack or 1 element at the stack if 0 is there then push -1 if 1 elemntb is there check the condition for it
#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	  stack<int>st;
	  for(int i=0;i<n;i++)
	  {
		  st.push(i);
	  }
	  while(!st.empty()&&st.size()>1)
	  {
		  int a=st.top();
		  st.pop();
		  int b=st.top();
		  st.pop();
		  if(knows(a,b)&&!knows(b,a))
		  {
			  st.push(b);
		  }
		  else if(knows(b,a)&&!knows(a,b))
		  {
			  st.push(a);
		  }
	  }
	  if(st.empty())
	  {
		  return -1;
	  }
	  else{
		  int m=st.top();
		  for(int i=0;i<n;i++)
		  {
			  if(i==m)
			  {
				  continue;
			  }
			  if((knows(m,i)))
			  {
				  return -1;
			  }
			  if(!knows(i,m))
			  {
				  return -1;
			  }
		  }
		  return m;
	  }
}
