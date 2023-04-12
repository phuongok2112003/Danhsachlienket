#include<iostream>
#include<iomanip>
using namespace std;

class VienChuc
{
	private:
		int ma_vc;
		string ho_ten;
		int tuoi;
		double he_so_luong;
	
	public:
		VienChuc()
		{
		}
		VienChuc(int ma_vc, string ho_ten, int tuoi, double he_so_luong)
		{
			this->ma_vc = ma_vc;
			this->ho_ten = ho_ten;
			this->tuoi = tuoi;
			this->he_so_luong = he_so_luong;
		}
		
		~VienChuc()
		{
		}
		
		friend istream& operator >> (istream &is, VienChuc &vc)
		{
			cout<<"Nhap ma vien chuc: ";
			is>>vc.ma_vc;
			cout<<"Nhap ho va ten vien chuc: ";
			cin.ignore();
			getline(is, vc.ho_ten);
			cout<<"Nhap tuoi: ";
			is>>vc.tuoi;
			cout<<"Nhap he so luong: ";
			is>>vc.he_so_luong;
			return is;
		}
		
		friend ostream& operator << (ostream &os, VienChuc vc)
		{
			os << setw(10) << vc.ma_vc << " | " 
			   << setw(20) << vc.ho_ten <<" | " 
			   << setw(5) << vc.tuoi <<" | " 
			   << setw(13) << vc.he_so_luong << " | ";
			return os;
		}
		
		int get_ma()
		{
			return ma_vc;
		}
};

class MonHoc
{
	private:
		string ten_mon_hoc;
		int so_tiet;
	public:
		MonHoc()
		{
		}
		MonHoc(string ten_mon_hoc, int so_tiet)
		{
			this->ten_mon_hoc = ten_mon_hoc;
			this->so_tiet = so_tiet;
		}
		
		~MonHoc()
		{
		}
		
		friend istream& operator >> (istream &is, MonHoc &mh)
		{
			cout<<"Nhap ten mon hoc: ";
			cin.ignore();
			getline(is,mh.ten_mon_hoc);
			cout<<"Nhap so tiet: ";
			is>>mh.so_tiet;
			return is;
		}
		
		friend ostream& operator << (ostream &os, MonHoc mh)
		{
			os << setw(15) << mh.ten_mon_hoc << " | " 
			   << setw(10) << mh.so_tiet     << " | " ;
			return os;
		}
};

class GiaoVien : public VienChuc, public MonHoc
{
	private:
		string bo_mon;
	public:
		GiaoVien()
		{
		}
		GiaoVien(int ma_vc, string ho_ten, int tuoi, double he_so_luong,
				string ten_mon_hoc, int so_tiet,
				string bo_mon)
				: VienChuc(ma_vc, ho_ten, tuoi, he_so_luong), MonHoc(ten_mon_hoc, so_tiet) 
		{
			this->bo_mon = bo_mon;
		}
		
		~GiaoVien()
		{
		}
		
		friend istream& operator >> (istream &is, GiaoVien &gv)
		{
			is>> (VienChuc&) gv;
			is>> (MonHoc&) gv;
			cout<<"Nhap ten bo mon: ";
			is.ignore();
			getline(is, gv.bo_mon);
			return is;
		}
		
		friend ostream& operator << (ostream &os, GiaoVien gv)
		{
			os << (VienChuc&) gv;
			os << (MonHoc&) gv;
			os << setw(15) << gv.bo_mon << endl;
			return os;
		}
};


struct GV
{
	GiaoVien data;
	GV *next;
};


void TieuDe();
void KhoiTaoDS(GV* &pHead);
void menu(GV* &pHead, int n);

void menu_1(GV* &pHead, int n);
void setList(GV* &pHead, int n);
GV *creatGV_setList(GiaoVien x);
void ThemCuoi_setList(GV* &pHead, GiaoVien x);

GV *creatGV();
void ThemCuoi(GV* &pHead);
void NhapDS(GV* &pHead, int n);

void InDS(GV *pHead);
void insertFirst(GV* &pHead, GV *a);
int Dem(GV *pHead);
void Them_vitri(GV* &pHead);
void SapXep(GV* &pHead);
GV *TimKiem(GV *pHead, int x);
void Xoa(GV* &pHead, GV *p);
void ThongBao_Xoa(GV* &pHead);


int main()
{
	GV *ds;
	int n; cout<<"Nhap so giao vien: "; cin>>n;
	KhoiTaoDS(ds);
	menu(ds,n);
	return 0;
}

void KhoiTaoDS(GV* &pHead)
{
	pHead = new GV;
	pHead = NULL;
}

GV *creatGV_setList(GiaoVien x)
{	
	GV *new_gv = new GV;
	new_gv->data = x;
	new_gv->next = NULL;	
	return new_gv;
}

void ThemCuoi_setList(GV* &pHead, GiaoVien x)
{
	GV *new_gv = creatGV_setList(x);
	if(pHead == NULL)
		pHead = new_gv;
	else
	{
		GV *p = pHead;
		while(p->next != NULL)
			p = p->next;
		p->next = new_gv;
	}
}

GV *creatGV()
{	
	GiaoVien x; 
	cin >> x;
	GV *new_gv = new GV;
	new_gv->data = x;
	new_gv->next = NULL;	
	return new_gv;
}

void ThemCuoi(GV *&pHead)
{
	GV *new_gv = creatGV();
	if(pHead == NULL)
		pHead = new_gv;
	else
	{
		GV *p = pHead;
		while(p->next != NULL)
			p = p->next;
		p->next = new_gv;
	}
}

void NhapDS(GV* &pHead, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"\n- Nhap giao vien thu: "<<i+1<<endl;
		ThemCuoi(pHead);
	}
}

void InDS(GV *pHead)
{
	if(pHead == NULL)
	{
		cout<<"\n--> Danh sach trong!!!\n";
		return;
	}
	GV *p = pHead;
	do
	{
		cout << p->data;
		p = p->next;
	}while(p != NULL);
}

void insertFirst(GV* &pHead, GV *a)
{
	if(pHead == NULL)	pHead = a;
	else
	{
		a->next = pHead;
		pHead = a;
	}
}

int Dem(GV *pHead)
{
	int dem = 0;
	GV *p = pHead;
	while(p != NULL)
	{
		p = p->next;
		dem++;
	}
	return dem;
}

void Them_vitri(GV* &pHead)
{
	cout<<"\n\n--> Nhap thong tin giao vien muon them:\n\n";
	GV *a = creatGV();
	int vi_tri;
	do
	{
		cout<<"\n-> Nhap vi tri muon them: "; cin>>vi_tri;
	}while(vi_tri <= 0 || vi_tri > Dem(pHead));
	
	if(vi_tri == 1)		insertFirst(pHead, a);
	else
	{
		int dem = 1;
		GV *p = pHead;
		while(dem < vi_tri)
		{
			p = p->next;
			dem++;
		}
		GV *q = pHead;
		while(q->next != p)		q= q->next;
		q->next = a;
		a->next = p;			
	}
}

void SapXep(GV* &pHead)
{
	for(GV *p = pHead; p->next != NULL; p = p->next)
		for(GV *q = p->next; q != NULL; q = q->next)
			if(p->data.get_ma() > q->data.get_ma())
				swap(p->data, q->data);
}

GV *TimKiem(GV *pHead, int x)
{
	GV *p = pHead;
	while(p != NULL && p->data.get_ma() != x)
		p = p->next;
	return p;
}

void Xoa(GV* &pHead, GV *p)
{
	if(pHead == NULL)
		cout<<"\n-> Danh sach trong!!!\n";
	else if(p == pHead)
	{
		GV *p = pHead;
		pHead = p->next;
		delete p;
		p = NULL;
	}
	else
	{
		GV *q = pHead;
		while(q->next != p)		q = q->next;
		q->next = p->next;
		delete p; 
		p = NULL;	
	}
}

void ThongBao_Xoa(GV* &pHead)
{
	int x; cout<<"\n\n--> Nhap ma can xoa: "; cin>>x;
	GV *p = TimKiem(pHead, x);
	if(p != NULL)
	{
		cout<<"\n--> Giao vien co trong danh sach\n\n----DANH SACH SAU KHI XOA----\n\n";
		Xoa(pHead, p);
		TieuDe();
		InDS(pHead);
	}
	else cout<<"\n--> Trong danh sach khong co giao vien can xoa"<<endl;
}


void TieuDe()
{
	cout << setw(10) << "MA" << " | " << setw(20) << "HO TEN" <<" | " << setw(5) << "TUOI" <<" | " << setw(13) << "HE SO LUONG" << " | "
	 << setw(15) << "TEN MON HOC" << " | " << setw(10) << "SO TIET" << " | "  << setw(15) << "TEN BO MON" << endl; 
}

void menu(GV* &pHead, int n)
{
	int lc;
		cout<<"\n- 1: Nhap du lieu tu danh sach co san";
		cout<<"\n- 2: Nhap du lieu tu ban phim";
		cout<<"\n-> Chon: "; cin>>lc;
		system("CLS");
		switch(lc)
		{
			case 1:
			{
				setList(pHead, n);
				menu_1(pHead, n);
				break;
			}	
			case 2:
			{
				NhapDS(pHead, n);
				menu_1(pHead, n);
				break;	
			}
		}		

}


void menu_1(GV* &pHead, int n)
{
	int lua_chon;
	
	do
	{
		cout<<"\n-------------------------------------------------------------------------------";
		cout<<"\n--------------------------------------MENU-------------------------------------";
		cout<<"\n- 1: In danh sach giao vien";
		cout<<"\n- 2: Them 1 nhan vien vao vi tri thu k";
		cout<<"\n- 3: Sap xep danh sach tang dan theo ma";		
		cout<<"\n- 4: Xoa giao vien co ma nhap tu ban phim";
		cout<<"\n- 0: Exit";
		cout<<"\n-------------------------------------------------------------------------------"<<endl;
		cout<<"\n-> Nhap lua chon: "; cin>>lua_chon;
		system("CLS");
		switch(lua_chon)
		{
			case 1:
			{
				cout<<"\n\n----DANH SACH GIAO VIEN----\n\n";
				TieuDe();
				InDS(pHead);
				break;
			}
			case 2:
			{
				cout<<"\n\n----DANH SACH GIAO VIEN SAU KHI THEM----\n\n";
				Them_vitri(pHead);
				TieuDe();
				InDS(pHead);
				break;
			}
			case 3:
			{
				SapXep(pHead);
				cout<<"\n\n----DANH SACH NHAN VIEN SAP XEP TANG DAN CUA MA----\n\n";
				TieuDe();
				InDS(pHead);
				break;
			}
			case 4:
			{
				ThongBao_Xoa(pHead);
				break;
			}
			case 0:
				break;
			default:
				{
					cout<<"\n-> Lua chon khong hop le!!!"; 
					break;
				}
		}
	}while(lua_chon);
		
}

void setList(GV* &pHead, int n)
{
	GiaoVien a[8];
	a[0] = {123, "Nguyen Van An", 26, 3, "Vat Ly", 10, "Tu Nhien"};
	a[1] = {13456, "Tran Thu Ha", 30, 4, "Ngu Van", 13, "Xa Hoi"};
	a[2] = {789, "Hoang Thu Trang", 25, 3, "Tieng Anh", 10, "Xa Hoi"};
	a[3] = {4444, "Tran van Hung", 40, 4, "Toan", 13, "Tu Nhien"};
	a[4] = {999, "Nguyen Tri Hung", 30, 4, "Hoa Hoc", 10, "Tu Nhien"};
	a[5] = {80, "Ta Van Luong", 25, 3, "The Duc", 10, "GDTC"};
	a[6] = {345, "Hoang Tuan Anh", 32, 4, "Sinh hoc", 10, "Tu Nhien"};
	a[7] = {90, "Le Thi Thu Ha", 43, 4, "Lich Su", 10, "Xa Hoi"};
	for(int i=0; i<n; i++)
	{
		ThemCuoi_setList(pHead,a[i]);
	}
	
}