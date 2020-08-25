#include<stdio.h>
#include<conio.h>
#define MaxLenght 1000

typedef struct {
	int arr[MaxLenght];
	int last;
}list;

void createNullList(list *L){
	L->last = -1;
}
int emptyList(list L){
	if(L.last < 0) return 1;	
	return 0;
}
void Insert_List(int x, int p, list *L)
{
	int i;
    if(L->last >= MaxLenght)
            printf("\tDanh sach day!");
    else
        if ((p<0) || (p > L->last+1))
                printf("\tVi tri khong hop le!");
        else
        {
            for(i = L->last; i >= p; i--)
                L->arr[i+1] = L->arr[i];
            
            L->last++;
            L->arr[p] = x;
		}
}
void readList(list *L){
    createNullList(L);
    int n, i;
    printf("\n\t-Nhap so phan tu cua sanh sach: "); scanf("%d", &n);

    for(i=0; i < n; i++)
    {
        printf("\t\t- Nhap phan tu thu %d: ", i+1);
		scanf("%d", &L->arr[i]);
		L->last++;
    }
}

void Print_List(list L)  {
	int i;
    if (emptyList(L)) printf("\t=> Danh sach rong!");
    else
        for(i=0; i <= L.last; i++)
            printf("%4d", L.arr[i]);
}
int sumList(list *L){
	int i;
	int sum = 0;
	for (i=0; i <= L->last; i++){
		sum += L->arr[i];
	}
	return sum;
}
int maxList(list L){
	int i;
	int max = L.arr[0];
	for (i = 0; i <= L.last; i++){
		if(L.arr[i]>max) max = L.arr[i];
	}
	return max;
}
int chanDau(list L){
	int i;
	for(i = 0; i < L.last; i++){
		if(L.arr[i]%2 == 0) return i;
	}
	return -1;
}
void xoaChanDau(list *L){
	int i;
	int vt =  chanDau(*L);
	if(vt == -1) printf("\n\t=>khong co phan tu chan de xoa!");
	else{
		for(i = vt; i <= L->last-1; i++){
			L->arr[i] = L->arr[i+1];
		}
		L->last--;
	}
}
int main(){
	list L;
    int x , p, key;
    
	do
    {
    	printf("\n\t--------Chuc nang--------\n");
        printf("\n\t1. Nhap danh sach");
        printf("\n\t2. Tinh tong cac phan tu trong ds");
        printf("\n\t3. In ra phan tu lon nhat");
        printf("\n\t4. Chen 1 phan tu vao ds");
        printf("\n\t5. Xoa phan tu chan dau tien");
        printf("\n\t0. Thoat chuong trinh");
        printf("\n\n\tBan lua chon: ");
        scanf("%d", &key);
        switch(key)
        {
        case 1:
            readList(&L);
            printf("\t==> Danh sach cua ban: ");
    		Print_List(L);
            break;
        case 2:
            printf("\n\t==> Tong danh sach cua ban: %d", sumList(&L));
            break;
        case 3:
            printf("\n\t==> Gia tri lon nhat trong danh sach la: %d", maxList(L));
            break;
        case 4:
            printf("\n\t-Chen them phan tu");
			printf("\n\t\t-Nhap vi tri can chen: ");
			scanf("%d", &p);
			printf("\t\t-Nhap gia tri can chen: ");
			scanf("%d", &x);
			Insert_List(x, p, &L);
			printf("\t==> Danh sach cua ban: ");
			Print_List(L);
            break;
		case 5:
            printf("\n\t-Xoa phan tu chan dau tien ");
			xoaChanDau(&L);
			printf("\n\t==> Danh sach cua ban: ");
			Print_List(L);
		    getch();
            break;	    
		case 0:
                printf("\nBan da chon thoat chuong trinh! Hay Nhan ENTER!");
                getch();
                return 0;
        default: printf("\n\tGia tri nhan khong dung!");
        		break;
        }
        printf("\n\tChuong trinh van dang chay\n");
    }
  while(1);
    getch();
    return 0;
}
	
