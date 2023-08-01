#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class clinic
{
    int age;
    char bg[5];
    char mno[11];
    char city[15];
    char tal[15];
    char dist[15];

protected:
    int id;
    char name[10];
    char lname[10];

public:

    void getdata();
    void showdata();
    void storedata();
    void storebill();
    void showbill(int);
    void searchdata(int);
    void searchdata();
    //void bill();
    void editdata(int);
    void update(int pid);
    void exit();

    bool validstring(char nam[])
    {
        int namelen,i;
        while(nam[i]!='\0')
        {
            i++;
        }

        namelen=i;
        for(int i=0; i<namelen; i++)
        {
            if(!isalpha(nam[i]) || namelen<3)
            {
                cout<<"INVALID";
                return false;
            }
        }
        return true;
    }

    void bloodgroup()
    {
        int ch;
        cout<<"\t\t1.A+"<<endl;
        cout<<"\t\t2.AB+"<<endl;
        cout<<"\t\t3.B+"<<endl;
        cout<<"\t\t4.O+"<<endl;
        cout<<"\t\t5.A-"<<endl;
        cout<<"\t\t6.AB-"<<endl;
        cout<<"\t\t7.B-"<<endl;
        cout<<"\t\t8.O-"<<endl;
        cout<<"Enter Your Choice ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            bg[0]='A';
            bg[1]='+';
            break;

        case 2:
            bg[0]='A';
            bg[1]='B';
            bg[2]='+';
            break;

        case 3:
            bg[0]='B';
            bg[1]='+';
            break;

        case 4:
            bg[0]='O';
            bg[1]='+';
            break;

        case 5:
            bg[0]='A';
            bg[1]='-';
            break;

        case 6:
            bg[0]='A';
            bg[1]='B';
            bg[2]='-';
            break;

        case 7:
            bg[0]='B';
            bg[1]='-';
            break;

        case 8:
            bg[0]='O';
            bg[1]='-';
            break;
        }

    }

    int getid()
    {
        int temp;
        fstream file;
        file.open("clinic.txt",ios::in|ios::out|ios::app);

        //file.seekg(0);
        file.read((char*)this,sizeof(*this));
        if(!file.eof())
        {
            do
            {
                file.read((char*)this,sizeof(*this));
                temp=id;
            }
            while(!file.eof());
            return temp+1;
        }

    else{
        return 1001;
            //cout<<"hello";
    }
    }
};


void clinic::getdata()
{
    cout<<"\n Patient ID ";
    id=getid();

    cout<<id;

    while(1)
    {
        cout<<"\nEnter Patient First Name \n";
        cin>>name;
        if(validstring(name))
            break;
    }

    while(1)
    {
        cout<<"\nEnter Patient Last Name \n";
        cin>>lname;
        if(validstring(lname))
            break;
    }


    do
    {
        cout<<"\nEnter Patient age \n";
        cin>>age;
        if(age>4 && age<100)
            break;
        else
            cout<<"Age not VALID "<<endl;
    }
    while(1);


    cout<<"\nChose Patient blood group \n";
    bloodgroup();

    cin.ignore();
    cout<<"\nEnter Patient Mobile No \n";
    int flag;
    do
    {
        flag=0;
        gets(mno);
        if (strlen(mno)==10)
        {

            for(int i=0; i<10; i++)
            {
                if(!isdigit(mno[i]))
                {
                    flag=1;
                }
            }
        }
        else
        {
            cout<<"NOT valid mobile number "<<endl;
            flag=1;
        }

        if(flag)
            cout<<"Reenter the mobile Number ";
        else
        {
            cout<<"Valid mobile Number "<<endl;
            break;
        }

    }
    while(flag);

    cout<<"\nEnter Patient Address \n";
    // cout<<"\tCity: ";
    while(1)
    {
        cout<<"\tCity: ";
        cin>>city;
        if(validstring(city))
            break;
        else
            cout<<"\nRe-enter city name: "<<endl;
    }

    while(1)
    {
        cout<<"\tTaluka: ";
        cin>>tal;
        if(validstring(tal))
            break;
        else
            cout<<"Re-enter Taluka name: "<<endl;
    }

    while(1)
    {
        cout<<"\tDistrict: ";
        cin>>dist;
        if(validstring(dist))
            break;
        else
            cout<<"Re-enter District name: "<<endl;
    }

    cout<<"-----------------------"<<endl;
}
void clinic:: showdata()
{
    cout<<"patient case no  \t"<<id<<endl;
    cout<<"patient First Name  \t"<<name<<endl;
    cout<<"patient Last Name  \t"<<lname<<endl;
    cout<<"patient age  \t\t"<<age<<endl;
    cout<<"patient blood group  \t"<<bg<<endl;
    //cout<<"Patient address  \t"<<address<<endl;
    cout<<"mobile Number  \t\t"<<mno<<endl;
    cout<<"**Patient Address** \n";
    cout<<"\tCity \t\t"<<city<<endl;
    cout<<"\tTaluka \t\t"<<tal<<endl;
    cout<<"\tDistrict \t"<<dist<<endl;

    cout<<"----------------------------------------------------------"<<endl;
}

void clinic:: storedata()
{
    ofstream fout;
    fout.open("clinic.txt",ios::app);
    fout.write((char *)this,sizeof(*this));
    fout.close();
    cout<<"\n Data is stored in file \n";
}


void clinic :: update(int pid)
{
    int val;
    fstream file;
    file.open("clinic.txt",ios::in|ios::out|ios::ate);

    file.seekg(0);

    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {

        if(id==pid)
        {
            val=file.tellp();
            file.seekp(val- sizeof(*this));
            getdata();
            storedata();
            break;
        }
        file.read((char*)this,sizeof(*this));
    }
}

void clinic:: storebill()
{
    ofstream fout;
    fout.open("data.txt",ios::app);
    fout.write((char *)this,sizeof(*this));
    fout.close();
    cout<<"\n Data is stored in file \n";
}

void clinic:: showbill(int pid)
{
    string line;
    ifstream myfile("data.txt");
    if(myfile.is_open())
    {
        while (getline (myfile,line))
        {
            cout<<line<<'\n';
        }
        myfile.close();
    }
    else cout<<"Unable to open the file";


}

void clinic::searchdata(int pid)
{
    ifstream fin;

    fin.open("clinic.txt",ios::in);
    if(!fin)
        cout<<"File is not opening ";

    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
        if(pid==id)
            showdata();

        fin.read((char *)this,sizeof(*this));
    }
}


void clinic::searchdata()
{
    ifstream fin;

    fin.open("clinic.txt",ios::in);
    if(!fin)
        cout<<"File is not opening ";

    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
        showdata();
        fin.read((char *)this,sizeof(*this));
    }
}


void clinic::exit()
{
    system("cls");
    cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                                           		                                  |@@\n";
    cout<<"\t@@|                               THANK YOU FOR USING                                     |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                            DENTAL CLINIC SYSTEM                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|                                                                                       |@@\n";
    cout<<"\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

}


class treatment:protected clinic
{
    int treatno;
    float docfee;
    float casefee;
    float treatfee;
    float total;

public:
    void bill();

};

void treatment::bill()
{
    int ch,total;
    int Doctorfees=100;
    int Casepaperfees=250;
    cout<<"Treatment Details "<<endl<<endl;

    cout<<"\t1.Scalling"<<endl<<endl;
    int scalling=100;

    cout<<"\t2.Silver Filling"<<endl<<endl;
    int silverfilling=100;

    cout<<"\t3.Root Canal Treatment"<<endl<<endl;
    int rootcanal=300;

    cout<<"\t4.Crown Prosthesis"<<endl<<endl;
    int crown=1280;

    cout<<"\t5.Complete Denture"<<endl<<endl;
    int complete=300;

    cout<<"\t6.Removable Partial Denture"<<endl<<endl;
    int removable=180;

    cout<<"\t7.Mucogingival Surgury"<<endl<<endl;
    int msurgury=1500;

    cout<<"\t8.Disimpaction"<<endl<<endl;
    int disimpaction=300;

    cout<<"\t9.Minir Oral Surgury"<<endl<<endl;
    int mos=1000;

    cout<<"\t10.Apicectomy"<<endl<<endl;
    int tomy=1500;

    cout<<"\t11.Composite Restoration"<<endl<<endl;
    int cr=300;

    cout<<"\t12.Fixed Bridge Prosthesis"<<endl<<endl;
    int fixed=4000;

    cout<<"Enter Your Choice "<<endl;
    cin>>ch;

    switch(ch)
    {
    case 1:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Scalling\t\t\t Rs.100"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=scalling+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 2:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Silver Filling\t\t Rs.100"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=silverfilling+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 3:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Root Canal Treatment\t\t Rs.300"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=rootcanal+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 4:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Crown Prosthesis\t\t Rs.1280"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=crown+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 5:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Complete Denture\t\t Rs.300"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=complete+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 6:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Removable Partial Denture\t Rs.180"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=removable+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 7:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Mucogingival Sugury\t\t Rs.1500"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=msurgury+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 8:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Disimpaction\t\t\t Rs.300"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=disimpaction+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 9:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Minir Oral Surgury\t\t Rs.1000"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=mos+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 10:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Apicectomy\t\t\t Rs.1500"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=tomy+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 11:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Composite Restoration\t\t Rs.300"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=cr+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;

    case 12:
        cout<<"treatment\t\t\tprice"<<endl<<endl;

        cout<<"1.Fixed Bridge Prosthesis\t Rs.4000"<<endl;
        cout<<"2.Doctorfees\t\t\t Rs.100"<<endl;
        cout<<"3.Casepaperfees\t\t\t Rs.250"<<endl;

        cout<<"*******************************************************************************"<<endl;
        total=fixed+Doctorfees+Casepaperfees;
        cout<<"Total\t\t\t\t"<<total<<endl;
        cout<<"*******************************************************************************"<<endl;
        break;
    }
}
int main()
{
    cout<<"****************************************************************************************************************************************"<<endl<<endl;
    cout<<"******************************************************* DENTAL CLINIC SYSYTEM *******************************************************"<<endl<<endl;
    cout<<"************************************************************** WELCOME **************************************************************"<<endl<<endl;
    cout<<"****************************************************************************************************************************************"<<endl<<endl;

    while(1)
    {
        int ch,pid;
        clinic c1;
        cout<<"\n\t  DENTAL CLINIC SYSTEM \n\n";
        cout<<"\n\tPlease,  Choose from the following Options: \n\n";
        cout<<"\t _________________________________________________________________ \n";
        cout<<"\t|                                           	                  |\n";
        cout<<"\t|             1  >> Add New Patient Record                        |\n";
        cout<<"\t|             2  >> Search the patient                            |\n";
        cout<<"\t|             3  >> Modify the data                               |\n";
        cout<<"\t|             4  >> All patient details                           |\n";
        cout<<"\t|             5  >> Generate the Bill                             |\n";
        cout<<"\t|             6  >> Full Histrory of patient                      |\n";
        cout<<"\t|             7  >> Exit                                          |\n";
        cout<<"\t|_________________________________________________________________|\n\n";

        cout<<"\nEnter your choice \n";
        cin>>ch;
        system("cls");

        switch(ch)
        {
        case 1:
            c1.getdata();
            c1.storedata();
            system("cls");
            break;

        case 2:
            cout<<"Enter the patient case paper to search ";
            cin>>pid;
            c1.searchdata(pid);
            break;

        case 3:
            cout<<"Enter the patient id to modify ";
            cin>>pid;
            c1.update(pid);
            break;

        case 4:
            cout<<"The details of all patients \n";
            c1.searchdata();
            break;

        case 5:
            cout<<"Enter the patient id\n";
            cin>>pid;
            //c1.bill();
            //c1.storebill();
            break;

        case 6:
            cout<<"Enter the patient id to see all history \n";
            cin>>pid;
            c1.showbill(pid);
            break;

        case 7:
            cout<<"Exiting from program \n";
            system("cls");
            cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout<<"\t@@ ______________________________________________________________________________ @@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                                           		                         |@@\n";
            cout<<"\t@@|                         THANK YOU FOR USING                                  |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                         DENTAL CLINIC SYSTEM                                 |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|                                                                              |@@\n";
            cout<<"\t@@|______________________________________________________________________________|@@\n";
            cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
            return 0;
            break;
        }
    }
}
