/*
	Reversing each word of a given string 
	Eg :	input  : Hello World 
			output : olleH dlroW

	1. Input a sentence as a string , convert it to a char array
	2. Pass the array to the reverse_str function
	3. Calculate the length of the array (Note sizeof function will not work here due to space's,
	   so we have to iterate through each element and calulate the length of the array )
	
	4. set two variable's , one to point to start & another to point to the end
	5. swap these variables
	6. update the variables
*/
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
char * reverse_str(char * str) {
	int length = 0,i=0,init=0;
	while(str[i]!='\0') {
		length++;
		i++;
	}
	for(int i=0,j=length-1;i<=j,j>=i;i++,j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}
int main(){
	string s;
	cout<<"Enter your string : ";
	getline(cin,s);
	char str[s.length()];
	strcpy(str,s.c_str());
	cout<<"After reversing each word is : "<<reverse_str(str)<<endl;
    return 0;
}