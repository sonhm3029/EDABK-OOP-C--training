#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <fstream>
const double PI = 3.14;

using namespace std;
//Khai bao cac kieu hinh:
enum shapeType{
	rectangle = 1,
	square,
	circle,
	triangle,
	line,
	ellipse
};
//khai bao cac lop:
class Edge;
//Hinh
class Hinh{
    protected:
    //Vi tri tam
        double x, y;
        double netVe;
        string type;
    //mau
        string color;
    //cac ham thanh vien
    public:
    //khai bao mang chua cac gia tri canh de thuc hien ghi file
        double get_x();
        double get_y();
        double get_netVe();
        string get_color();
        virtual string get_type();
        /////////////////////
        virtual void Draw();
        virtual void set();
        //Ham tinh chu vi:
        virtual double chuVi() = 0;
        //Ham tinh dien tich:
        virtual double dienTich() = 0;
        // khai bao toan tu
        bool operator < (Hinh &k)
        {
            if(chuVi()<k.chuVi())
            {
                return true;
            }
            return false;
        }
        virtual void readFromFile(ifstream &file) = 0;
        virtual void writeIntoFile(ofstream &file) = 0;
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
string Hinh::get_type()
{
    return type;
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
        void readFromFile(ifstream &file);
        void writeIntoFile(ofstream &file);
};

//Thuc hien ham

double HCN::get_chieuDai() { return chieuDai;}
double HCN::get_chieuRong() { return chieuRong;}
void HCN::Draw()
{
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(17)<<"(cdai, crong)"<<endl;
    cout<<setw(10)<<"HCN"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(10)<<"("<<chieuDai<<", "<<chieuRong<<")";

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
void HCN::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>chieuDai>>data>>chieuRong>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void HCN::writeIntoFile(ofstream &file)
{
    file<<"shape{rect,"<<x<<","<<y<<","<<chieuDai<<","<<chieuRong<<","<<color<<","<<netVe<<"}"<<endl;
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
    void readFromFile(ifstream &file);
    void writeIntoFile(ofstream &file);
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(15)<<"canh"<<endl;
    cout<<setw(10)<<"Vuong"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(13)<<a;
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
void Vuong::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>a>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void Vuong::writeIntoFile(ofstream &file)
{
    file<<"shape{square,"<<x<<","<<y<<","<<a<<","<<color<<","<<netVe<<"}"<<endl;
}
/////////////////////////////////////////////////////////////////////////
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
        void readFromFile(ifstream &file);
        void writeIntoFile(ofstream &file);
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(15)<<"ban kinh"<<endl;
    cout<<setw(10)<<"Tron"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(14)<<R;

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
void Tron::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>R>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void Tron::writeIntoFile(ofstream &file)
{
    file<<"shape{cir,"<<x<<","<<y<<","<<R<<","<<color<<","<<netVe<<"}"<<endl;
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
        void readFromFile(ifstream &file);
        void writeIntoFile(ofstream &file);
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(15)<<"3 canh"<<endl;
    cout<<setw(10)<<"Tam giac"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(10)<<"("<<a<<", "<<b<<", "<<c<<")";
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
void tamGiac::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>a>>data>>b>>data>>c>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void tamGiac::writeIntoFile(ofstream &file)
{
    file<<"shape{tri,"<<x<<","<<y<<","<<a<<","<<b<<","<<c<<","<<color<<","<<netVe<<"}"<<endl;
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
        void readFromFile(ifstream &file);
        void writeIntoFile(ofstream &file);
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(18)<<"(tdai, tngan)"<<endl;
    cout<<setw(10)<<"Ellipse"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(10)<<"("<<trucDai<<", "<<trucNgan<<")";

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
void Ellipse::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>trucDai>>data>>trucNgan>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void Ellipse::writeIntoFile(ofstream &file)
{
    file<<"shape{ellip,"<<x<<","<<y<<","<<trucDai<<","<<trucNgan<<","<<color<<","<<netVe<<"}"<<endl;
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
        void readFromFile(ifstream &file);
        void writeIntoFile(ofstream &file);
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
    cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"type"<<setw(20)<<"tam"<<setw(10)<<"mau"<<setw(20)<<"do day"<<setw(15)<<"chu vi"<<setw(15)<<"dien tich"<<setw(15)<<"chieu dai"<<endl;
    cout<<setw(10)<<"Line"<<setw(15)<<"("<<this->get_x()<<", "<<this->get_y()<<")";
    cout<<setw(10)<<this->get_color()<<setw(20)<<this->get_netVe()<<setw(15)<<chuVi()<<setw(15)<<dienTich()<<setw(14)<<dai;
} 
void Line::readFromFile(ifstream &file)
{
    char data;
    file>>x>>data>>y>>data>>dai>>data;
    getline(file,color,',');
    file>>netVe>>data;
}
void Line::writeIntoFile(ofstream &file)
{
    file<<"shape{line,"<<x<<","<<y<<","<<dai<<","<<color<<","<<netVe<<"}"<<endl;
}

//EDGE
class Edge{
    // double x, y;//toa do tam khong can dung nua
    string color;
    double doDay;
    Hinh *H1, *H2;
    //vi tri cua h1 va h2 trong List
    int vtH1, vtH2;
    public:
        void set();
        void get();
        void setH1_H2(Hinh *h1, Hinh *h2);
        bool isLinkEdge(Hinh *h);//kiem tra xem canh nay co noi hinh
        void setIndex(int vt1, int vt2);//lay vi tri cua h1 va h2
        int getIndex1() { return vtH1;}
        int getIndex2() {return vtH2;}
        // lay mau sac va do day:
        string getColor() { return color;}
        double getNetVe() { return doDay; }
        void readFromFile(ifstream &file)
        {
            char data;
            file>>vtH1>>data>>vtH2>>data;
            getline(file,color,',');
            file>>doDay>>data;
        }
        void writeIntoFile(ofstream &file)
        {
            file<<"edge{"<<vtH1<<","<<vtH2<<","<<color<<","<<doDay<<"}"<<endl;
        }
};

void Edge::setH1_H2(Hinh *h1, Hinh *h2)
{
    H1 = h1;
    H2 = h2;
    // x = (H1->get_x()+H2->get_x())*0.5;
    // y = (H1->get_y()+H2->get_y())*0.5;
}
void Edge::set()
{
    cout<<"\nNhap vao mau sac: ";cin>>color;
    cout<<"Nhap vao do day net ve: ";cin>>doDay;
}
void Edge::get()
{
    cout<<"Duong noi tam giua hai hinh:";
    cout<<"\n H1: "; H1->Draw();
    cout<<"\n H2:";
    H2->Draw();
    // cout<<"\t\nToa do tam: ("<<x<<", "<<y<<")";
    cout<<"\t\nMau:"<<color;
    cout<<"\t\nNet ve: "<<doDay;
}
bool Edge::isLinkEdge(Hinh *h)
{
    if(h == H1|| h == H2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Edge::setIndex(int vt1, int vt2)
{
    vtH1 = vt1;
    vtH2 = vt2;
}
/////////////////////////////////////////                   FACTORY              ////////////////////////////////////
class shapeFactory{
	public:
	//create product:
	Hinh* createShape(shapeType type){
		Hinh *h;
		switch(type)
		{
			case rectangle:  h = new HCN;  break;
			case square:     h = new Vuong; break;
			case circle:     h = new Tron; break;
			case triangle:   h = new tamGiac; break;
			case line:       h = new Line; break;
			case ellipse:    h = new Ellipse; break;
		}
		return h;
	}
    Hinh* createShape1(string type)
    {
        Hinh *h;
        if(type == "rect")
        {
            h= new HCN;
        }
        else if(type == "square")
        {
            h= new Vuong;
        }
        else if(type == "cir")
        {
            h= new Tron;
        }
        else if(type == "tri")
        {
            h= new tamGiac;
        }
        else if(type == "line")
        {
            h= new Line;
        }
        else if(type == "ellip")
        {
            h= new Ellipse;
        }
        return h;
    }
};
///////////////////////////////////////////////              GRAPH                  /////////////////////////////////////////////////////////
class graph{
    shapeFactory factory;
    vector<Hinh*> List;
    vector<Edge*> listEdge;
    vector<Hinh*> shadowList;// anh cua List de khi thuc hien cac option show thi thu tu cac hinh ban dau van giu nguyen
	public:
        graph()
        {
            cout<<"\n----------BAT DAU CHUONG TRINH----------";
        }
        ~graph()
        {
            cout<<"\n\n";
            cout<<"\n--------CHUONG TRINH KET THUC----------";
            cout<<"\n--------------THANKS !-----------------";
            cout<<"\n\n\n";
        }
        char chose;
		void menu();// CHUONG TRINH
		char menuLuaChon();// MENU LUA CHON CHINH
		void taoHinh(); // TAO HINH
		void menuShow();// MENU CHON KIEU SHOW HINH
		void timTheoTam();// TIM HINH THEO TAM
		void buildEdge();// TAO CANH NOI TAM
		void display();// IN RA CAC HINH DA TAO
		void reverseDisplay();// IN NGUOC
		void setListEdge();// TAO LIST CAC CANH NOI TAM
		void displayListEdge();// SHOW CAC CANH NOI TAM
		void displayEdge2();// SHOW CANH NOI TAM CUA MOT HINH BAT KI
		void increasingC();// SAP XEP TANG DAN CHU VI
		void increasingS();// SAP XEP TANG DAN DIEN TICH
        void readFile();
        void writeFile();
        void normalDisplay();//in hinh ra theo dung thu tu ban dau cua List
};
void graph::taoHinh()
{
	char loai;
    double a, b;
	shapeFactory set;
    string color;
	void menuHinh();
	do{
		menuHinh();
		cout<<"\nLua chon cua ban la: ";cin>>loai;
		switch(loai)
		{
			case '1': List.push_back(set.createShape(rectangle));	break;
			case '2': List.push_back(set.createShape(square));		break;
			case '3': List.push_back(set.createShape(circle));		break;
			case '4': List.push_back(set.createShape(triangle));	break;
			case '5': List.push_back(set.createShape(line));		break;
			case '6': List.push_back(set.createShape(ellipse));	break;
			case '7': 									break;
			default: cout<<"\nKhong hop le moi ban nhap lai"; break;
		}
		if(loai == '1'||loai == '2'||loai == '3'||loai == '4'||loai == '5'||loai == '6')
		{
			List.back()->set();
            shadowList.push_back(List.back());
		}
	}while(loai != '7');
}
//in ra binh thuong lay thu tu ban dau nhap hinh
void graph::normalDisplay()
{
    int count = 0;
    if(List.size() == 0)
    {
        cout<<"\n Chua co hinh nao duoc tao!";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    else{
        cout<<"\nCac hinh da tao la: "<<endl;
        for( int i = 0; i<List.size(); i++)
        {
            count +=1;
            cout<<"\t"<<count<<".";List[i]->Draw();
            cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
}
//in ra danh cho shadow
void graph::display(){
    int count = 0;
    if(List.size() == 0)
    {
        cout<<"\n Chua co hinh nao duoc tao!";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    else{
        cout<<"\nCac hinh da tao la: "<<endl;
        for( int i = 0; i<shadowList.size(); i++)
        {
            count +=1;
            cout<<"\t"<<count<<".";shadowList[i]->Draw();
            cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
}
//in ra theo chieu nguoc lai:
void graph::reverseDisplay(){
    int count = 0;
    if(List.size() == 0)
    {
        cout<<"\n Chua co hinh nao duoc tao!";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    else{
        cout<<"\nCac hinh da tao la: "<<endl;
        for( int i = shadowList.size() - 1; i>=0; i--)
        {
            count +=1;
            cout<<"\t"<<count<<".";shadowList[i]->Draw();
            cout<<"\n-------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
}
//set list edge
void graph::setListEdge()
{
    int i, j;
    display();
    if(List.size() <=1)
    {
        cout<<"\nBan phai co it nhat hai hinh da duoc tao, vui long tao them hinh !";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    if(List.size() >= 2)
    {
        do{
            cout<<"\nNhap vao 2 hinh ma ban muon !";
            cout<<"\nNhap vao hinh thu nhat: ";cin>>i;
            cout<<"\nNhap vao hinh thu hai : ";cin>>j;
            if(i > List.size()|| j >List.size()||i <=0||j <=0)
            {
                cout<<"\nKhong hop le moi ban nhap lai !";
                cout<<"\n-------------------------------------------------------------------------------------------------------------";
            }
        } while(i > List.size()|| j >List.size()||i <=0||j <=0);
        listEdge.push_back(new Edge);
        listEdge.back()->setH1_H2(List[i-1], List[j-1]);
        listEdge.back()->set();
        listEdge.back()->setIndex(i, j);
    }
}

//show list edge
void graph::displayListEdge()
{
    int count = 0;
    if(listEdge.size() == 0)
    {
        cout<<"\nChua co canh noi tam nao duoc tao !";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    else{
        cout<<"\n#############################################################################################################";
        cout<<"\nCac canh noi tam da tao la: "<<endl;
        for(int i = 0; i<listEdge.size(); i++)
        {
            count +=1;
            cout<<"\t"<<count<<".";listEdge[i]->get();
            cout<<"\n#############################################################################################################"<<endl;
        }
    }
}
//show list edge cho hinh bat ki
void graph::displayEdge2()
{
    int k;
    int dem = 0;
    display();
    if(List.size() == 1 || listEdge.size() == 0)
    {
        cout<<"\nBan chua them hinh noi tam hoac chua co hinh nao duoc tao !";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }
    else{
        do{
            cout<<"\nNhap vao hinh ban muon xem: ";cin>>k;
            cout<<"\n-------------------------------------------------------------------------------------------------------------";
            if(k>List.size()||k <=0)
            {
                cout<<"\nKhong ho le, moi nhap lai !";
                cout<<"\n-------------------------------------------------------------------------------------------------------------";
            }
        }while(k>List.size()|| k<=0);
        cout<<"\nCac canh noi tam cua hinh da chon la: ";
        for(int i = 0; i<listEdge.size(); i++)
        {
            if(listEdge[i]->isLinkEdge(List[k-1]) == true)
            {
                dem += 1;
                cout<<"\n"<<dem<<". ";listEdge[i]->get();
                cout<<"\n#############################################################################################################"<<endl;
            }
        }
        if(dem == 0)
        {
            cout<<"\nHinh da chon khong co canh noi tam !";
            cout<<"\n-------------------------------------------------------------------------------------------------------------";
        }
        dem = 0;
    }
}
bool compareC( Hinh* &a, Hinh* &b)
{
    return a->chuVi()<b->chuVi();
}
bool compareS(Hinh* &a, Hinh* &b)
{
    return a->dienTich()<b->dienTich();
}
//tang chu vi
void graph::increasingC()
{
    sort(shadowList.begin(), shadowList.end(), compareC);
}
//tang dien dich
void graph::increasingS()
{
    sort(shadowList.begin(), shadowList.end(), compareS);
}
//giam dien tich
//Ham tim kiem hinh theo toa do tam:
void graph::timTheoTam()
{
    double x1, y1;
    int count = 0;//dau hieu de nhan biet la co hinh hay khong
    string chon;
    do{
        cout<<"\nNhap vao tam can tim: ";
        cout<<"\nNhap vao x: ";cin>>x1;
        cout<<"\nNhap vao y: ";cin>>y1;
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
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
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }while(chon == "y"|| chon== "Y");
}

char graph::menuLuaChon()
{
    char chon;
    cout<<"\n---------------LUA CHON----------------"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"| 1.        Tao hinh moi               |";
        cout<<"\n| 2.    Show tat ca hinh da tao        |";
        cout<<"\n| 3.    Tim hinh theo toa do tam       |";
        cout<<"\n| 4.      Them duong noi tam           |";
        cout<<"\n| 5.           Doc File                |";
        cout<<"\n| 6.           Ghi File                |";
        cout<<"\n| 7.            Exit                   |"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Lua chon cua ban la: ";cin>>chon;
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
        return chon;
}
void menuHinh()
{
    cout<<"\nNhap loai hinh muon tao: ";
    cout<<"\n1. HCN\n2. Vuong\n3. Tron\n4. Tam giac\n5. Duong thang\n6. Ellipse\n7. Quay ve menu";
    cout<<"\n-------------------------------------------------------------------------------------------------------------";
}
void graph::menuShow()
{
    char luaChon;
    do{
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
        cout<<"\nChon mot trong cac lua chon sau: ";
        cout<<"\n1. In ra binh thuong";
        cout<<"\n2. In ra theo thu tu tang dan chu vi";
        cout<<"\n3. In ra theo thu tu giam dan chu vi";
        cout<<"\n4. In ra theo thu tu tang dan dien tich";
        cout<<"\n5. In ra theo thu tu giam dan dien tich";
        cout<<"\n6. Quay lai Menu";
        cout<<"\nLua chon cua ban la: ";cin>>luaChon;
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
        switch(luaChon)
        {
            case '1':
                normalDisplay();
            break;
            case '2':
                cout<<"\nDS HINH SAP XEP THEO CHIEU TANG DAN CHU VI LA: ";
                increasingC();
                display();//in ra theo chieu tu dau mang
            break;
            case '3':
                cout<<"\nDS HINH SAP XEP THEO CHIEU GIAM DAN CHU VI LA: ";
                increasingC();
                reverseDisplay();//in ra theo chieu tu cuoi len
            break;
            case '4':
                cout<<"\nDS HINH SAP XEP THEO CHIEU TAN DAN DIEN TICH LA: ";
                increasingS();
                display();
            break;
            case '5':
                cout<<"\nDS HINH SAP XEP THEO CHIEU GIAM DAN DIEN TICH LA: ";
                increasingS();
                reverseDisplay();//in ra theo chieu tu cuoi len
            break;
            case '6':
            break;
            default:
                cout<<"\nKhong hop le moi nhap lai: ";
            break;
        }

    }while(luaChon !='6');
}

void graph::buildEdge()
{
    char key;
    do{
        cout<<"\n1. Them canh noi tam hai hinh ";
        cout<<"\n2. Show cac canh noi tam da tao";
        cout<<"\n3, Show canh noi tam cua hinh bat ki";
        cout<<"\n4. Quay lai menu";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
        cout<<"\nLua chon cua ban la: ";cin>>key;
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
        switch(key)
        {
            case '1':
                setListEdge();//them canh noi tam
            break;
            case '2':
                displayListEdge();//Show tat cacac canh noi tam da tao
            break;
            case '3':
                displayEdge2();//Show cac canh noi tam cho hinh bat ki
            break;
            case '4':
            break;
            default:
                cout<<"\nKhong hop le, moi ban nhap lai: ";
            break;
        }
    }while(key >='0' && key !='4');
}
void graph::writeFile()
{
    cout<<"\n-------------------------------------------------------------------------------------------------------------";
    cout<<"\nDang ghi file";
    if(List.size() !=0)
    {
        ofstream outfile;
        outfile.open("shape.txt");
        ////////////////////////////////////////GHI VAO FILE CAC HINH////////////////////////////////////////////
        for(int i = 0; i<List.size();i++)
        {
            List[i]->writeIntoFile(outfile);
        }
        for(int i = 0; i<listEdge.size(); i++)
        {
            listEdge[i]->writeIntoFile(outfile);
        }
        outfile.close();
    }else
    {
        cout<<"\nChua co du lieu, vui long nhap them !";
        cout<<"\n-------------------------------------------------------------------------------------------------------------";
    }  
}
void graph::readFile()
{
    int soDong = 0;
    ifstream infile;
    infile.open("shape.txt");
    string line;
    while(getline(infile,line)){ ++soDong;}
    cout<<"\nDnag doc file...";
    infile.clear();//reset der doc lai tu dau
    infile.seekg(0);
    if(soDong !=0)
    {
        while(soDong >0 &&infile.eof() == false)
        {
            string kind ;
            getline(infile,kind,'{');
            if( kind == "shape")
            {
                Hinh *h;
                string type;
                getline(infile, type,',');
                h = factory.createShape1(type);
                h->readFromFile(infile);
                List.push_back(h);
                shadowList.push_back(h);
            }
            else if( kind == "edge")
            {
                Edge *e = new Edge;
                e->readFromFile(infile);
                listEdge.push_back(e);
            }
            string xuongDong;
            getline(infile,xuongDong,'\n');
            --soDong;
        }
        for(int i = 0; i<listEdge.size(); i++)
        {
            int x = listEdge[i]->getIndex1();
            int y = listEdge[i]->getIndex2();
            listEdge[i]->setH1_H2(List[x-1],List[y-1]);
        }
    } else{
            cout<<"\nFile rong !";
            cout<<"\n--------------------------------------------------------------------------------";
    }
    infile.close();
}
void graph::menu()
{
	do{
        //HIEN THI RA MAN HINH MENU CHINH
        chose = menuLuaChon();
        switch(chose)
        {
            case '1'://menu chon hinh
                taoHinh();
                cout<<"\n-------------------------------------------------------------------------------------------------------------";
            break;
            case '2':
                menuShow();
            break;
            case '3':
                timTheoTam();
            break;
            case '4':
                buildEdge();
            break;
            case '5':
                readFile();
            break;
            case '6':
                writeFile();
            break;
            case '7':
            break;
            default:
                cout<<"\nKhong ho le moi nhap lai";
                cout<<"\n-------------------------------------------------------------------------------------------------------------";
            break;
        }
    }while(chose !='1'&&chose !='2'&&chose !='3'&&chose !='4'&&chose !='5'&&chose !='6'&&chose !='7');
}

int main()
{
	graph g;
	do{
		g.menu();
	}while(g.chose != '7');
    return 0;
}