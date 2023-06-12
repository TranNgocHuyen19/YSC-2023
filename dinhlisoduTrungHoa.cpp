#include <stdio.h>
int Gcd (int a, int b);
//Tim UCLN
void Input(int &n, int m[100], int a[100]);
void Coprime (int n, int m[100], int a[100]);
//Kiem tra cac so m1, m2, m3,..., mk la so nguyen to cung nhau khong, neu khong yeu cau nhap lai
long Euclid_Extended (int a,int b);
//Nghiem cua dinh li so du trung hoa
// x dong du voi a1.N1.y1+a2.N2.y2.....+an.Nn.yn(mod M)
int main (){
    int m[100],a[100],N[100],y[100];
    int n;
    long long M=1,x=1,temp=1;
    printf("Nhap so phuong trinh dong du: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Nhap m(%d)",i+1);
        scanf("%d",&m[i]);
        printf("Nhap a(%d)",i+1);
        scanf("%d",&a[i]);
    }
	Coprime(n,m,a);
	printf("La cac so nguyen to cung nhau.\n");
    for(int i=0;i<n;i++){
        printf("x dong du voi a(%d)(mod %d)\n",a[i],m[i]);
    }
    for(int i=0;i<n;i++){
        M*=m[i];
    }
    for(int i=0;i<n;i++){
        N[i]=M/m[i];
    }
	for (int i=0;i<n;i++){
		y[i]=Euclid_Extended(N[i],m[i]) ;
		printf("y(%d)=%d\n",i+1,y[i]);
	}
    for(int i=0;i<n;i++){
    	x+=a[i]*N[i]*y[i];
	}
	printf("x= %ld + k*%d",x,M);
}
int Gcd (int a, int b){
	if(b==0) return a;
	return Gcd(b, a%b);
}
void Input(int &n, int m[100], int a[100]){
	for(int i=0;i<n;i++){
        printf("Nhap m(%d)",i+1);
        scanf("%d",&m[i]);
        printf("Nhap a(%d)",i+1);
        scanf("%d",&a[i]);
    }
}
void Coprime (int n, int m[100], int a[100]){
	for(int i=0; i<n; i++){
    	for(int j=i+1; j<n; j++){
    		if(Gcd(m[i],m[j])!=1){
    			printf("Khong phai la cac so nguyen to cung nhau.\n");
    			printf("Nhap lai!\n");
    			Input(n,m,a);
    			Coprime(n,m,a);
			}
		}
	}
}
//Tim nghich dao cua module m[i] voi y[i]=(Ni)^-1 (mod mi) 
long Euclid_Extended (int a,int b){ //a^-1 mod b tim x:ax=1(mod b) ax+by=1
	long r,q,y0=1,y1=0,y,temp=b;
	while(b!=0){
	r=a%b;
	q=a/b;
	if (r==0) break;
	y=y0-q*y1;
	a=b;
	b=r;
	y0=y1;
	y1=y;
	}
	if(y>=0) return y;
	else return y+temp;
}




