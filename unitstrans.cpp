#include<iostream>
#include<map>
#include<string>
#include<cmath> 
using namespace std;
typedef map<string,double> Mapsi;
class units{
public://��λ��Աinsert  �ڵ�λ���������µ�λ�ķ��� 
	void Mapsi_insert(Mapsi *mapsi,string ch,double n){
		mapsi->insert(Mapsi::value_type(ch,n));
	}
	virtual bool Find(string,string)=0;//����find�������������ﶼ����Ҫ�����Զ���һ�����麯����Ϊ����ķ����� 
private: 
};
class Basic_units:public units{
public:
	Basic_units():index(0){
		//���ȵ�λԤ��
		//����Ӧ����length.insert(Mapsi::value_type("m",1))�����Ұ�insert����������˸��� 
		u[0]="length";
		Mapsi_insert(&total[u[0]],"m",1);
		Mapsi_insert(&total[u[0]],"km",0.001);
		Mapsi_insert(&total[u[0]],"dm",10);
		Mapsi_insert(&total[u[0]],"cm",100);
		Mapsi_insert(&total[u[0]],"mm",1000);
		Mapsi_insert(&total[u[0]],"um",1000000);
		Mapsi_insert(&total[u[0]],"nm",1000000000);
		Mapsi_insert(&total[u[0]],"nmi",0.00053996);//���� 
		Mapsi_insert(&total[u[0]],"mi",0.00062137);//Ӣ��
		Mapsi_insert(&total[u[0]],"in",39.37007874);//Ӣ�� 
		Mapsi_insert(&total[u[0]],"yd",1.0936133);//�� 
		Mapsi_insert(&total[u[0]],"ft",3.2808399);//Ӣ�� 
		Mapsi_insert(&total[u[0]],"fur",0.00497097);//��¡ 
		Mapsi_insert(&total[u[0]],"��",0.002);
		Mapsi_insert(&total[u[0]],"��",3.00030003);
		Mapsi_insert(&total[u[0]],"��",300.030003);
		Mapsi_insert(&total[u[0]],"��",0.30003);
		Mapsi_insert(&total[u[0]],"��",30.0030003);
		Mapsi_insert(&total[u[0]],"��",3000.30003);
		
		u[1]="weight";
		Mapsi_insert(&total[u[1]],"g",1);
		Mapsi_insert(&total[u[1]],"kg",0.001);
		Mapsi_insert(&total[u[1]],"t",0.000001);
		Mapsi_insert(&total[u[1]],"mg",1000);
		Mapsi_insert(&total[u[1]],"dwt",0.73487421);//ӢǮ 
		Mapsi_insert(&total[u[1]],"oz",0.03527396);// ��˾
		Mapsi_insert(&total[u[1]],"lb",0.00220462);//�� 
		Mapsi_insert(&total[u[1]],"dr",0.56438339);//���� 
		Mapsi_insert(&total[u[1]],"��",0.02);
		Mapsi_insert(&total[u[1]],"Ǯ",0.2);
		Mapsi_insert(&total[u[1]],"�н�",0.002);
		
		u[2]="time";
		Mapsi_insert(&total[u[2]],"week",1);
		Mapsi_insert(&total[u[2]],"day",7);
		Mapsi_insert(&total[u[2]],"h",168);
		Mapsi_insert(&total[u[2]],"min",10080);
		Mapsi_insert(&total[u[2]],"s",604800);
		Mapsi_insert(&total[u[2]],"ms",604800000);
		Mapsi_insert(&total[u[2]],"us",604800000000);//����u���� 
		Mapsi_insert(&total[u[2]],"ns",604800000000000);
		Mapsi_insert(&total[u[2]],"month",0.23333333333333);
		Mapsi_insert(&total[u[2]],"year",0.019178082191781);
		
		u[3]="ele";
		Mapsi_insert(&total[u[3]],"A",1);
		Mapsi_insert(&total[u[3]],"kA",pow(10,-3));
		Mapsi_insert(&total[u[3]],"MA",pow(10,-6));
		Mapsi_insert(&total[u[3]],"GA",pow(10,-9));
		Mapsi_insert(&total[u[3]],"mA",pow(10,3));
		Mapsi_insert(&total[u[3]],"uA",pow(10,6));
		Mapsi_insert(&total[u[3]],"nA",pow(10,9));
		Mapsi_insert(&total[u[3]],"C/s",10);
		
	}
	virtual bool Find(string st1,string st2){
		for(int i=0;i<4;i++){
			Mapsi::iterator it1=total[u[i]].find(st1),it2=total[u[i]].find(st2);
			if(it1!=total[u[i]].end()&&it2!=total[u[i]].end()){
				index=i;
				return true; 
			} 
		}
		return false;
	}
	double result(double x,string st1,string st2){
		return x*total[u[index]][st2]/total[u[index]][st1];
	}
private:
	map<string,Mapsi> total;
	int index;
	string u[4];
};
int main(){
	double n;
	string st1,st2;
	cout<<"Please put in a number��";
	cin>>n;
	cout<<"Please put in it's unit��";
	cin>>st1; 
	cout<<"Please put in it's next unit��" ;
	cin>>st2;
	Basic_units Bu;
	if(Bu.Find(st1,st2)){
		cout<<"result: "<<Bu.result(n,st1,st2)<<endl;
	}
		else{
			cout<<"My program is too low to identify your units."<<endl;
		}
	return 0;
}
