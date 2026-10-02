#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;

class item{

char name[20];
char main_group[25];
char cat[20];
char sub_cat[20];
int no;
int id;
int curr_stocks;
int min_stocks;
int unit;
double qty;
double price;

public:
void input(){
    fstream file;
    file.open("proj.txt",ios::app | ios::binary);
    int i;
    char name[20][20]={"Atta","Besan","Ghee","Olive Oil","Namak","Kali Mirch","Towar Dal","Sabudana","Tomato Ketchup","Kaju","Badam","Kalava","Roli","Nariyal","Javitri","Walnuts","Saunf","Chawal","Chole","Rajma"};
    char main_group[25][20]={"Edible","Edible","Edible","Edible","Edible","Edible","Edible","Edible","Edible","Edible","Edible","Non Edible","Non Edible","Edible","Edible","Edible","Edible","Edible","Edible","Edible"};
    char cat[20][20]={"Staple Food","Staple Food","Cooking Essentials","Cooking Essentials","Cooking Essentials","Cooking Essentials","Staple Food","Vrat Foods","Preserved Foods","Nuts","Nuts","Religious Items","Religious Items","Nuts","Seeds","Nuts","Spices","Staple Food","Staple Food","Staple Food"};
    char sub_cat[20][20]={"Flours","Flours","Oil","Oil","Spices","Spices","Pulses","Grain","Ketchups","Dry Fruits","Dry Fruits","Threads","Powder","Dry Coconut","Whole Spices","Dry Fruits","Whole Spices","Pulses","Pulses","Pulses"};
    int id[20]={2601,2602,2603,2604,2605,2606,2607,2608,2609,2610,2611,2612,2613,2614,2615,2616,2617,2618,2619,2620};
    int curr_stocks[20]={100,50,40,80,70,30,20,80,100,70,5,25,67,90,76,120,90,35,60,78};
    int min_stocks[20]={50,30,30,50,50,40,50,50,80,50,20,50,70,40,55,60,55,30,55,50};
    int unit[20]={100,100,80,80,70,30,40,80,20,35,50,50,67,90,76,24,45,35,120,78};
    double qty[20]={1,0.5,0.5,1,1,1,0.5,1,5,2,0.1,0.5,1,1,1,5,2,1,0.5,1};
    double price[20]={50,70,200,250,150,40,60,80,100,90,700,85,95,100,85,10,55,50,90,120};
    int no[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  for(i=0;i<20;i++){
   strcpy(this->name,name[i]);
    strcpy(this->main_group,main_group[i]);
    strcpy(this->cat,cat[i]);
    strcpy(this->sub_cat,sub_cat[i]);
    this->id=id[i];
    this->curr_stocks=curr_stocks[i];
    this->min_stocks=min_stocks[i];
    this->unit=unit[i];
    this->qty=qty[i];
    this->price=price[i];
    this->no=no[i];
       file.write((char*)this,sizeof(*this));
  }
  cout<<"Data inserted successfully "<<endl;
  file.close();
}
void print(){
    fstream file;
    file.open("proj.txt",ios::in | ios::binary);
    int i;
    for(int i=0;i<160;i++){
cout<<"-";
}
cout<<"\n";
     cout<<left<<setw(6)<<"S.No."<<"| ";
     cout<<left<<setw(15)<<"Item Name"<<"| ";
      cout<<left<<setw(8)<<"Item Id"<<"| ";
      cout<<left<<setw(14)<<"Main Group"<<"| ";
      cout<<left<<setw(22)<<"Category"<<"| ";
      cout<<left<<setw(15)<<"Sub Category"<<"| ";
      cout<<left<<setw(18)<<"Curr. Stocks"<<"| ";
      cout<<left<<setw(18)<<"Min. Stocks"<<"| ";
      cout<<left<<setw(8)<<"Unit"<<"| ";
      cout<<left<<setw(8)<<"Qty(kg)"<<"| ";
      cout<<left<<setw(6)<<"Price"<<"| ";
      cout<<endl;
for(int i=0;i<160;i++){
cout<<"-";
}
cout<<"\n";
int j=1;
 while(file.read((char*)this,sizeof(*this))){
            cout<<left<<setw(6)<<j<<"| ";
             cout<<left<<setw(15)<<this->name<< "| ";
            cout<<left<<setw(8)<<this->id<<"| ";
             cout<<left<<setw(14)<<this->main_group<<"| ";
             cout<<left<<setw(22)<<this->cat<<"| ";
             cout<<left<<setw(15)<<this->sub_cat<<"| ";
             cout<<left<<setw(18)<<this->curr_stocks<<"| ";
             cout<<left<<setw(18)<<this->min_stocks<<"| ";
             cout<<left<<setw(8)<<this->unit<<"| ";
             cout<<left<<setw(8)<<this->qty<<"| ";
             cout<<left<<setw(6)<<this->price<<"| "<<endl;
             j++;
}
for(int i=0;i<160;i++){
cout<<"-";
}
file.close();
}

void modify()
{
    int m = -1, id;
    int pos;

    fstream file;
    file.open("proj.txt", ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "File could not be opened!" << endl;
        return;
    }

    cout << "Enter item id to modify: ";
    cin >> id;

    while (file.read((char*)this, sizeof(*this)))
    {
        pos = file.tellg() - sizeof(*this);

        if (id == this->id)
        {
            cout << "\nName of item: " << this->name << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->name;
            }

            cout << "\nCategory of item: " << this->cat << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->cat;
            }

            cout << "\nSub Category of item: " << this->sub_cat << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->sub_cat;
            }

            cout << "\nCurrent Stocks of item: " << this->curr_stocks << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->curr_stocks;
            }

            cout << "\nMinimum Stocks of item: " << this->min_stocks << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->min_stocks;
            }

            cout << "\nUnit of item: " << this->unit << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->unit;
            }

            cout << "\nQuantity of item: " << this->qty << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->qty;
            }

            cout << "\nPrice of item: " << this->price << endl;
            cout << "Change the value? (1 = Yes, 0 = No): ";
            cin >> m;

            if (m == 1)
            {
                cout << "Enter New Value: ";
                cin >> this->price;
            }

            // Move write pointer to beginning of current record
            file.clear();
            file.seekp(pos, ios::beg);

            // Write complete updated record
            file.write((char*)this, sizeof(*this));

            cout << "\nRecord modified successfully!" << endl;

            break;
        }
    }

    if (file.eof())
    {
        cout << "\nItem ID not found!" << endl;
    }

    file.close();

    print();
}
void del(){
    int r;
        fstream file;
       fstream fs;
       file.open("proj.txt",ios::in |ios::binary);
       fs.open("temp.txt",ios::out | ios::binary);
       cout<<"Enter item id to delete data: "<<endl;
       cin>>r;
       while(1)
       {
           file.read((char*)this,sizeof(*this));
           if(file.eof())break;
           if(this->id!=r){
            fs.write((char*)this,sizeof(*this));
       }
    }
       file.close();
       fs.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
       cout<<endl<<"Record deleted"<<endl;
       print();
}

void main_cat_record(){
    int r=-1,count=0;
    fstream file,fstemp;
    file.open("proj.txt",ios::in | ios::binary);
    fstemp.open("temp.txt",ios::out | ios::binary);
    cout<<endl<<"Enter Main Group to see records: "<<endl;
    cout<<"For Edible: Select 0"<<endl;
    cout<<"For Non Edible : Select 1"<<endl;
    cin>>r;
    while(1)
       {
           file.read((char*)this,sizeof(*this));
           if(file.eof())break;
           if(r==0&&!strcmp(this->main_group,"Edible")){
            fstemp.write((char*)this,sizeof(*this));
            count++;
        }
        else if(r==1&&!strcmp(this->main_group,"Non Edible")){
            fstemp.write((char*)this,sizeof(*this));
            count++;
           }   
        }
    file.close();
       fstemp.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
print();
 cout<<endl<<"Total Items: "<<count<<endl;  
}

void stock_comparison(){
int count=0;
    fstream file,fstemp;
    file.open("proj.txt",ios::in | ios::binary);
    fstemp.open("temp.txt",ios::out | ios::binary);
    cout<<endl<<"Items whose stocks are lesser than Base Stock Level: "<<endl;
    while(1){
        file.read((char*)this,sizeof(*this));
         if(file.eof())break;
        if(this->curr_stocks<this->min_stocks){
            fstemp.write((char*)this,sizeof(*this));
            count++;  
        } 
    }
        file.close();
       fstemp.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
    print();
 cout<<endl<<"Total Items: "<<count<<endl; 
}

void price_comparison(int a,int b=10000){
int count=0;
    fstream file,fstemp;
    file.open("proj.txt",ios::in | ios::binary);
    fstemp.open("temp.txt",ios::out | ios::binary);
    cout<<endl<<"Items whose price is less than rs 100 but greater than rs 50: "<<endl;
    while(1){
        file.read((char*)this,sizeof(*this));
         if(file.eof())break;
        if(this->price<=b && this->price>=a){
            fstemp.write((char*)this,sizeof(*this));
            count++;  
        } 
    }
        file.close();
       fstemp.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
    print();
 cout<<endl<<"Total Items: "<<count<<endl; 
}

void sorted_rec(){
    int i=0;
    fstream fs;
    fstream file;
    vector<double>v;
    multimap<double,item>m;
    file.open("proj.txt",ios::in|ios::binary);
    fs.open("temp.txt",ios::out|ios::binary);
    while(1){
        file.read((char*)this,sizeof(*this));
        if(file.eof()){break;}
        v.push_back(this->price);
        m.insert({this->price, *this});
    }
    sort(v.begin(),v.end());

while(i < v.size())
{
    auto range = m.equal_range(v[i]);

    for(auto it = range.first; it != range.second; it++)
    {
        fs.write((char*)&(it->second), sizeof(item));
    }

    while(i < v.size() - 1 && v[i] == v[i + 1])
    {
        i++;
    }

    i++;
}
  file.close();
       fs.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
    print();   
}

void alphabet_sort(){
    fstream file,fs;
    vector<item>v;
    file.open("proj.txt",ios::in|ios::binary);
    fs.open("temp.txt",ios::out|ios::binary);
while(1){
    file.read((char*)this,sizeof(*this));
    if(file.eof()){break;}
    v.push_back(*this);
}
sort(v.begin(), v.end(), [](item a, item b){
    return strcmp(a.name, b.name) < 0;
});
for(int i = 0; i < v.size(); i++)
{
    fs.write((char*)&v[i], sizeof(item));
}
file.close();
       fs.close();
       remove("proj.txt");
       rename("temp.txt","proj.txt");
    print();  
}

void menu(){
    int r=-1,a=0,b=0;
        for(int i=0;i<150;i++){
            cout<<"_";
        }
        cout<<endl<<endl<<"                                                File Handling Project"<<endl;
        for(int i=0;i<150;i++){
            cout<<"_";
        }
        cout<<endl;
        while(1){
            cout<<endl<<"Choose Operations: "<<endl;
            cout<<endl;
            cout<<"Press 1 : Input the Record"<<endl;
            cout<<endl;
            cout<<"Press 2 : Print the Record"<<endl;
            cout<<endl;
            cout<<"Press 3 : Modify the Record"<<endl;
            cout<<endl;
            cout<<"Press 4 : Delete the Record"<<endl;
            cout<<endl;
            cout<<"Press 5 : Categorize the Record on the basis of Main Group"<<endl;
            cout<<endl;
            cout<<"Press 6 : Records whose Stocks are less than minimum Stocks"<<endl;
            cout<<endl;
            cout<<"Press 7 : Categorize the Record on the basis of Price"<<endl;
            cout<<endl;
            cout<<"Press 8 : Sort the Record according to Price"<<endl;
            cout<<endl;
            cout<<"Press 9 : Sort the Record alphabetically"<<endl;
            cout<<endl;
            cout<<"Press 10 : Exit..."<<endl;
            cout<<endl;

            cin>>r;
            if(r==1){
               input(); 
            }
            if(r==2){
             print();   
            }
            if(r==3){
              modify();  
            }
            if(r==4){
              del();  
            }
            if(r==5){
              main_cat_record();  
            }
            if(r==6){
              stock_comparison();  
            }
            if(r==7){
                cout<<"Enter Min. amount to categorize: "<<endl;
                cin>>a;
                cout<<"Enter Max. amount (if any): otherwise enter 0 "<<endl;
                cin>>b;
                if(b!=0){
                price_comparison(a,b);
                }
                else{
                    price_comparison(a);
                }  
            }
            if(r==8){
              sorted_rec();  
            }
            if(r==9){
                alphabet_sort();
            }
            if(r==10){
                break;
            }
        }
        
}
};

int main(){
    item a;
    a.menu();
    return 0;
}