#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
const double PI = 3.14;

using namespace std;

//khai bao cac lop:
//Hinh
class Hinh{
    //Vi tri tam
    double x, y;
    double netVe;
    //mau
    string color;
    //cac ham thanh vien
    public:
        double get_x();
        double get_y();
        double get_netVe();
        string get_color();
        /////////////////////
        virtual void Draw();
        virtual void set();
        //Ham tinh chu vi:
        virtual double chuVi() = 0;
        //Ham tinh dien tich:
        virtual double dienTich() = 0;
};  

//Thuc hien ham
double Hinh::get_x(){ return x;}
double Hinh::get_y(){ return y;}
string Hinh::get_color() { return color;}
double Hinh::get_netVe() { return netVe;}
void Hinh::Draw(){}

void Hinh::set() {
    cout<<"Nhap vao toa do tam: "<<endl;
    cout<<"x = "; cin>>x;
    cout<<"y = ";cin>>y;
    cout<<"Nhap vao mau sac: ";cin>>color;
    cout<<"Nhap vao do day net ve: ";cin>>netVe;
}



//HCN
class HCN:public Hinh{
    //khai bao hai canh
    double chieuDai, chieuRong;
    public:
        double get_chieuDai();
        double get_chieuRong();
        void Draw();
        void set();
        //tinh chu vi:
        double chuVi();
        //tinh dien tich: 
        double dienTich();
};

//Thuc hien ham

double HCN::get_chieuDai() { return chieuDai;}
double HCN::get_chieuRong() { return chieuRong;}
void HCN::Draw()
{
    cout<<"Hinh chu nhat co tam ("<< this->get_x() <<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Chieu dai: "<<this->get_chieuDai()<<"\n\t  Chieu rong: "<<this->get_chieuRong()<<endl;
    cout<<"\t  Mau sac: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();
}

void HCN::set()
{
    Hinh::set();
    cout<<"Nhap vao chieu dai: ";
    cin>>chieuDai;
    do{
        cout<<"Nhap vao chieu rong: ";
        cin>>chieuRong;
        if( chieuRong > chieuDai)
        {
            cout<<"\nKhong hop le. Chieu rong phai nho hon chieu dai."<<endl;
        }
    } while (chieuRong > chieuDai);
}
//tinh chu vi, dien tich :
double HCN::chuVi()
{
    return (chieuDai + chieuRong) * 2;
}
double HCN::dienTich()
{
    return chieuDai*chieuRong;
}

//Vuong
class Vuong: public Hinh{
    //khai bao canh
    double a;
    //ham thanh vien 
    public:
    double get_canh();
    void Draw();
    void set();
    double chuVi();
    double dienTich();
};

//Thuc hien ham

void Vuong::set()
{
    Hinh::set();
    cout<<"Nhap vao canh cua hinh vuong: ";
    cin>>a;
}
double Vuong::get_canh(){ return a;}
void Vuong::Draw()
{
    cout<<"Hinh vuong co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Canh a = "<<this->get_canh()<<"\n\t  Mau: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();
}
//tinh chu vi va dien tich:
double Vuong::chuVi()
{
    return 4*a;
}
double Vuong::dienTich()
{
    return a*a;
}

//Tron

class Tron: public Hinh{
    //khai bao ban kinh
    double R;
    //ham thanh vien
    public:
        void set();
        double get_R();
        //ham ve
        void Draw();
        double chuVi();
        double dienTich();
};

//Thuc hien ham

void Tron::set()
{
    Hinh::set();
    cout<<"Nhap vao ban kinh cua hinh tron: ";
    cin>>R;
}
double Tron::get_R() {return R;}

void Tron::Draw()
{
    cout<<"Hinh tron co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Ban kinh R = "<<this->get_R()<<"\n\t  Mau: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();

}
//tinh chu vi va dien tich:
double Tron::chuVi()
{
    return PI*2*R;
}
double Tron::dienTich()
{
    return PI*R*R;
}

//Tam giac

class tamGiac: public Hinh{
    //do dai ba canh
    double a, b, c;
    //ham thanh vien
    public:
        void set();
        double get_canh1();
        double get_canh2();
        double get_canh3();
        //ham ve
        void Draw();
        //tinh chu vi, dien tich
        double chuVi();
        double dienTich();
};

//Thuc hien ham

void tamGiac::set()
{   
    Hinh::set();
    do{
        cout<<"Nhap vao canh 1: "; cin>>a;
        cout<<"Nhap vao canh 2: ";cin>>b;
        cout<<"Nhap vao canh 3: ";cin>>c;
        if(a+b<=c||a+c<=b||b+c<=a)
        {
            cout<<"------------------------------------------------------------------------------";
            cout<<"\nKhong hop le.\nDo dai 3 canh tam giac phai thoa man: a+b>c va a+c>b va b+c>a"<<endl;
            cout<<"Vui long nhap lai: \n"<<endl;
        }
    } while(a+b<=c||a+c<=b||b+c<=a);

}
double tamGiac::get_canh1() { return a;}
double tamGiac::get_canh2() { return b;}
double tamGiac::get_canh3() { return c;}
void tamGiac::Draw()
{
    cout<<"Tam giac co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Co do dai ba canh lan luot la: "<<this->get_canh1()<<", "<<this->get_canh2()<<", "<<this->get_canh3()<<endl;
    cout<<"\t  Mau sac: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();

}
//tinh chu vi va dien tich
double tamGiac::chuVi()
{
    return a+b+c;
}
double tamGiac::dienTich()
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//Ellipse

class Ellipse: public Hinh{
    double trucNgan, trucDai;
    public:
        void set();
        double get_trucNgan();
        double get_trucDai();
        void Draw(); 
        //tinh chu vi va dien tich
        double chuVi();
        double dienTich();
};


//Thuc hien ham

void Ellipse::set()
{
    Hinh::set();
    cout<<"Nhap vao truc ngan: ";cin>>trucNgan;
    cout<<"Nhap vao truc dai: "; cin>>trucDai;
}
double Ellipse::get_trucDai() { return trucDai;}
double Ellipse::get_trucNgan() { return trucNgan;}
void Ellipse::Draw()
{
    cout<<"Hinh ellipse co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Truc ngan: "<<this->get_trucNgan()<<"\n\t  Truc dai: "<<this->get_trucDai()<<endl;
    cout<<"\t  Mau sac: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();

}
//tinh chu vi va dien tich
double Ellipse::chuVi()
{
    return PI*(trucDai + trucNgan);
}
double Ellipse::dienTich()
{
    return trucDai*trucNgan*PI;
}

//Line
class Line: public Hinh{
    double dai;
    public:
        void set();
        double get_dai();
        void Draw();
        //chu vi va dien tich:
        double chuVi( ) {return 0;}
        double dienTich() { return 0;}
};

//thuc hien ham

void Line::set()
{
    Hinh::set();
    cout<<"Nhap vao chieu dai duong thang: ";cin>>dai;
}
double Line::get_dai() { return dai;}
void Line::Draw()
{
    cout<<"Duong thang co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Do dai: "<<this->get_dai()<<"\n\t  Mau: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
    cout<<"\n\t  chu vi: "<<chuVi();
    cout<<"\n\t  dien tich : "<<dienTich();

} 
//CAC HAM CUA CHUONG TRINH:
void taoHinh(int x, vector<Hinh*>& List)
{
    double a, b;
    string color;
    switch(x)
    {
        case 1:
            List.push_back(new HCN);
            List.back()->set();
        break;
        case 2:
            List.push_back(new Vuong);
            List.back()->set();
        break;
        case 3:
            List.push_back(new Tron);
            List.back()->set();
        break;
        case 4:
            List.push_back(new tamGiac);
            List.back()->set();
        break;
        case 5:
            List.push_back(new Line);
            List.back()->set();
        break;
        case 6:
            List.push_back(new Ellipse);
            List.back()->set();
        break;
        case 7:
        break;
        default:
            cout<<"\nKhong hop le, quay ve menu!";
        break;
    }
}


void display(vector<Hinh*>& List){
    int count = 0;
    if(List.size() == 0)
    {
        cout<<"\n Chua co hinh nao duoc tao!";
        cout<<"\n--------------------------------------------";
    }
    else{
        cout<<"\nCac hinh da tao la: "<<endl;
        for( int i = 0; i<List.size(); i++)
        {
            count +=1;
            cout<<"\t"<<count<<".";List[i]->Draw();
            cout<<"\n------------------------------"<<endl;
        }
    }
}
//tang dien tich
void increasingC(vector<Hinh*>& List)
{
    for(int i = 0; i<List.size(); i++)
    {
        for(int j = i+1; j<List.size(); j++)
        {
            if(List[j]->chuVi()<List[i]->chuVi())
            {
                swap(List[i], List[j]);
            }
        }
    }
}
//giam dien tich
void decreasingC(vector<Hinh*>& List)
{
    for(int i = 0; i<List.size(); i++)
    {
        for(int j = i+1; j<List.size(); j++)
        {
            if(List[i]->chuVi()<List[j]->chuVi())
            {
                swap(List[i], List[j]);
            }
        }
    }
}
//tang dien dich
void increasingS(vector<Hinh*>& List)
{
    for(int i = 0; i<List.size(); i++)
    {
        for(int j = i+1; j<List.size(); j++)
        {
            if(List[j]->dienTich()<List[i]->dienTich())
            {
                swap(List[i], List[j]);
            }
        }
    }
}
//giam dien tich
void decreasingS(vector<Hinh*>& List)
{
    for(int i = 0; i<List.size(); i++)
    {
        for(int j = i+1; j<List.size(); j++)
        {
            if(List[i]->dienTich()<List[j]->dienTich())
            {
                swap(List[i], List[j]);
            }
        }
    }
}
//Ham tim kiem hinh theo toa do tam:
void timTheoTam(vector<Hinh*>&List)
{
    double x1, y1;
    int count = 0, dauHieu;//dau hieu de nhan biet la co hinh hay khong
    string chon;
    do{
        cout<<"\nNhap vao tam can tim: ";
        cout<<"\nNhap vao x: ";cin>>x1;
        cout<<"\nNhap vao y: ";cin>>y1;
        cout<<"\n-------------------------------------------------------------------------------------";
        cout<<"\nKet qua tim kiem : "<<endl;
        for( int i = 0; i<List.size(); i++)
        {
            if( List[i]->get_x() == x1 && List[i]->get_y() == y1)
            {
                count ++;
                cout<<count<<". ";List[i]->Draw();cout<<endl;
            }
        }
        if(count == 0)
        {
            cout<<"\nKhong co hinh ma ban tim kiem";
        }
        cout<<"\nBan co muon tim tiep khong (Y/N): ";
        cin>>chon;
        count = 0;
        cout<<"\n---------------------------------------------------------------------------------";
    }while(chon == "y"|| chon== "Y");
}

int main()
{
    vector<Hinh*> List;
    List.resize(0);
    int chose, loai;
    do{
        cout<<"\n---------------LUA CHON----------------"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"| 1.        Tao hinh moi               |";
        cout<<"\n| 2.    Show tat ca hinh da tao        |";
        cout<<"\n| 3.    Tim hinh theo toa do tam       |";
        cout<<"\n| 4.            Exit                   |"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Lua chon cua ban la: ";cin>>chose;
        cout<<"\n----------------------------------------------------";
        switch(chose)
        {
            case 1:
                cout<<"\nNhap loai hinh muon tao: ";
                cout<<"\n1. HCN\n2. Vuong\n3. Tron\n4. Tam giac\n5. Duong thang\n6. Ellipse\n7. Quay ve menu";
                cout<<"\n------------------------------------------------";
                cout<<"\nLua chon cua ban la: ";cin>>loai;
                taoHinh(loai, List);
                cout<<"\n----------------------------------------------";
            break;
            case 2:
                int luaChon;
                do{
                    cout<<"\n-------------------------------------------------------------";
                    cout<<"\nChon mot trong cac lua chon sau: ";
                    cout<<"\n1. In ra binh thuong";
                    cout<<"\n2. In ra theo thu tu tang dan chu vi";
                    cout<<"\n3. In ra theo thu tu giam dan chu vi";
                    cout<<"\n4. In ra theo thu tu tang dan dien tich";
                    cout<<"\n5. In ra theo thu tu giam dan dien tich";
                    cout<<"\n6. Quay lai Menu";
                    cout<<"\nLua chon cua ban la: ";cin>>luaChon;
                    cout<<"\n-------------------------------------------------------------";
                    switch(luaChon)
                    {
                        case 1:
                            display(List);
                        break;
                        case 2:
                            cout<<"\nDS HINH SAP XEP THEO CHIEU TANG DAN CHU VI LA: ";
                            increasingC(List);
                            display(List);
                        break;
                        case 3:
                            cout<<"\nDS HINH SAP XEP THEO CHIEU GIAM DAN CHU VI LA: ";
                            decreasingC(List);
                            display(List);
                        break;
                        case 4:
                            cout<<"\nDS HINH SAP XEP THEO CHIEU TAN DAN DIEN TICH LA: ";
                            increasingS(List);
                            display(List);
                        break;
                        case 5:
                            cout<<"\nDS HINH SAP XEP THEO CHIEU GIAM DAN DIEN TICH LA: ";
                            decreasingS(List);
                            display(List);
                        break;
                        case 6:
                        break;
                        default:
                            cout<<"\nKhong hop le moi nhap lai: ";
                        break;
                    }

                }while(luaChon !=6);
            break;
            case 3:
                timTheoTam(List);
            break;
            case 4:
                cout<<"\n\n";
                cout<<"\n--------CHUONG TRINH KET THUC----------";
                cout<<"\n--------------THANKS !-----------------";
                cout<<"\n\n\n";
            break;
            default:
                cout<<"\nKhong ho le moi nhap lai";
            break;
        }
    }while(chose >= 1 &&chose<4);
    return 0;
}