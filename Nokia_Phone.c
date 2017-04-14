#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *in, *out;
	
	in= fopen("in1.txt", "rb");
	out= fopen("oo1.txt", "wb");
	
	if(in==NULL || out==NULL) {
		printf("File Error");
		exit(0);
	}
	
	char ch;
	int flag1=0, flag2=0, flag3=0, flag4=0, flag5=0, flag7=0;
	int count=0;
	
	do {
		ch= fgetc(in);
		printf("f");
		
		if(ch=='\n'){
			fputs("\r\n", out);
			fputs("\r\n", out);
			flag1=0;
			flag2=0;
			flag3=0;
			flag4=0;
			flag5=0;
			flag7=0;
			count++;
		}
		
		if(((ch>=65 && ch<=90 )|| (ch>=97 && ch<=122)) && flag2==0) {
			fputs("First name:	", out);
			fputc(ch, out);
			flag2=1;
		} else if(((ch>=65 && ch<=90 )|| (ch>=97 && ch<=122)) && flag2==1 && flag1==0) {
			fputc(ch, out);
		}
		
		if(ch==' ' && flag2==1 && flag1==0 && flag3==0) {
			flag1=1;
			flag3=1;
			fputs("\r\n", out);
			fputs("Last name:	", out);
			continue;
		}
		
		if(((ch>=65 && ch<=90 )|| (ch>=97 && ch<=122) || ch==' ') && flag3==1 && flag2==1 && flag1==1) {
			fputc(ch, out);
		}
		
		if(ch=='"' && flag3==1 && flag2==1) {
			flag2=0;
			flag3=0;
			fputs("\r\n", out);
			fputs("General phone:	", out);
		}
		
		if(((ch>=48 && ch<=57) || ch=='+' || ch=='*' || ch=='#')&& flag4==0) {
			flag5=1;
			fputc(ch, out);
		}
		if(ch==',' && flag5==1) {
			flag5=0;
			flag4=1;
			flag7=1;
		}
		if(ch=='"' && flag7==1) {
			flag7=0;
			fputs("\r\n", out);
			fputs("General mobile:	", out);
		}
			
		if(((ch>=48 && ch<=57) || ch=='+' || ch=='*' || ch=='#')&& flag4==1) {
			//flag5=1;
			fputc(ch, out);
			
		}
		
		
		
		
	} while (ch != '@' || ch != '/');
	
	printf("%d", count);
	return 0;
}
