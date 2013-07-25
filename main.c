
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char myBuffer[4];
	int c, startWrite=0;
	FILE *fp = fopen("alinanDosya.txt", "r");
	if (fp == NULL) { printf("Dosya acilamadi\n"); exit(0); }
	else
	{
		myBuffer[3] = '\0';
		do
		{
			c = getc(fp);

			//Bufferdaki verileri kaydır
			myBuffer[0] = myBuffer[1];
			myBuffer[1] = myBuffer[2];
			myBuffer[2] = c;
			
			//Yazma modu aktifse okunan karakteri yaz
			if(startWrite==1) printf("%c",c);

			//Eğer yazma modunda değilsen ATG okuduğunda yazma moduna gir
			if(myBuffer[0]=='A' && myBuffer[1]=='T' && myBuffer[2]=='G' && startWrite==0) { printf("ATG"); startWrite=1; }

			//Yazma modunda isen TAA, TGA veya TAG okuduğunda yazma modunu durdur.
			if(myBuffer[0]=='T' && myBuffer[1]=='A' && myBuffer[2]=='A' && startWrite==1) { printf("\n"); startWrite=0; }
			if(myBuffer[0]=='T' && myBuffer[1]=='A' && myBuffer[2]=='G' && startWrite==1) { printf("\n"); startWrite=0; }
			if(myBuffer[0]=='T' && myBuffer[1]=='G' && myBuffer[2]=='A' && startWrite==1) { printf("\n"); startWrite=0; }
		} while (c != EOF);
	}
	fclose(fp);
	return 0;
}
