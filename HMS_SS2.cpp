#include <iostream>
#include <string>
#include <vector>

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
};  
//HCN
class HCN:public Hinh{
    //khai bao hai canh
    double chieuDai, chieuRong;
    public:
        double get_chieuDai();
        double get_chieuRong();
        void Draw();
        void set();
};
//Vuong
class Vuong: public Hinh{
    //khai bao canh
    double a;
    //ham thanh vien 
    public:
    double get_canh();
    void Draw();
    void set();
};
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
};
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
};
//Oval

class Oval: public Hinh{
    double trucNgan, trucDai;
    public:
        void set();
        double get_trucNgan();
        double get_trucDai();
        void Draw(); 
};
//Line
class Line: public Hinh{
    double dai;
    public:
        void set();
        double get_dai();
        void Draw();
};


// Thuc hien cac lop:
//Hinh
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
double HCN::get_chieuDai() { return chieuDai;}
double HCN::get_chieuRong() { return chieuRong;}
void HCN::Draw()
{
    cout<<"Hinh chu nhat co tam ("<< this->get_x() <<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Chieu dai: "<<this->get_chieuDai()<<"\n\t  Chieu rong: "<<this->get_chieuRong()<<endl;
    cout<<"\t  Mau sac: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();
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

//Vuong
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
}

//Tron
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

}

//Tam Giac
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

}

//Oval
void Oval::set()
{
    Hinh::set();
    cout<<"Nhap vao truc ngan: ";cin>>trucNgan;
    cout<<"Nhap vao truc dai: "; cin>>trucDai;
}
double Oval::get_trucDai() { return trucDai;}
double Oval::get_trucNgan() { return trucNgan;}
void Oval::Draw()
{
    cout<<"Hinh oval co tam ("<<this->get_x()<<", "<<this->get_y()<<")"<<endl;
    cout<<"\t  Truc ngan: "<<this->get_trucNgan()<<"\n\t  Truc dai: "<<this->get_trucDai()<<endl;
    cout<<"\t  Mau sac: "<<this->get_color();
    cout<<"\n\t  Do day net ve: "<<this->get_netVe();

}

//Line

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

}

void taoHinh(int x, vector<Hinh*>& List)
{
    double a, b;
    string color;
    switch(x)
    {
        case 1:
            List.push_back(new HCN());
            List.back()->set();
        break;
        case 2:
            List.push_back(new Vuong());
            List.back()->set();
        break;
        case 3:
            List.push_back(new Tron());
            List.back()->set();
        break;
        case 4:
            List.push_back(new tamGiac());
            List.back()->set();
        break;
        case 5:
            List.push_back(new Line());
            List.back()->set();
        break;
        case 6:
            List.push_back(new Oval());
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
        cout<<"\n| 3.            Exit                   |"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Lua chon cua ban la: ";cin>>chose;
        cout<<"\n----------------------------------------------------";
        switch(chose)
        {
            case 1:
                cout<<"\nNhap loai hinh muon tao: ";
                cout<<"\n1. HCN\n2. Vuong\n3. Tron\n4. Tam giac\n5. Duong thang\n6. Oval\n7. Quay ve menu";
                cout<<"\n------------------------------------------------";
                cout<<"\nLua chon cua ban la: ";cin>>loai;
                taoHinh(loai, List);
                cout<<"\n----------------------------------------------";
            break;
            case 2:
                display(List);
            break;
            case 3:
                cout<<"\n\n";
                cout<<"\n--------CHUONG TRINH KET THUC----------";
                cout<<"\n--------------THANKS !-----------------";
                cout<<"\n\n\n";
            break;
            default:
                cout<<"\nKhong ho le moi nhap lai";
            break;
        }
    }while(chose == 1||chose ==2||chose !=1 && chose != 2 && chose != 3);
    return 0;
}