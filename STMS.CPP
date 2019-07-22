#include <iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>




int welcome();
void WELCOME();

class base{
    int day1,month1,year1,day2,month2,year2,nl[20];
    int x,y,z,ns,mar[20],durd,h1,ti[7],dmar[20];
    char name[20],name1[10],course[20],mpre[20],ch;
    float hr[10],weig[20][40],weigs[20],sumwe;
    char nsub[20][20],lesson[20][40][20];
    int temp[50],dur;
    long pword;

public:
    void getdata();
    void about();
    void help();
    void open();
    int day(int[],int);
    void End();
    long base::getrno(){
    return(pword);
    }
}b;




void base::open() /*to open account */
{

    int iday,imonth,iyear,comp[50];
    float subh[20],lesh[20][40],subhd[20][40],ctime,hr2[7],temp2[50];
    float subod[20][10],addh=0,remin;
    int td[7],diff,h,remark[40];
    char option,opt;
    clrscr();
    textcolor(CYAN);
    cprintf("Account details : ");
    cout<<"\n\t\t\t";
    textcolor(12);
    cprintf(name);
    cout<<" ";
    cprintf(name1);
    cprintf("\r\n");textcolor(1);
    cprintf("\r___________________________________________________________\r\n\n");
    cprintf("Welcome to STMS monitor.\r\n");
    cout<<"Name of Course : ";
    cprintf(course);
    cout<<"\r\n";
    cout<<"Name of subject :\n";
    for(x=0;x<ns;x++)
    {
	cout<<"\t"<<x+1<<" : ";
	cprintf(nsub[x]);
	cout<<"\r\n";

    }
    cout<<"Method of preparation : "<<mpre<<"\n";
    textcolor(15);
    cprintf("Goal duration : \r\n");
    cout<<"\t From : ";
    cout<<day1<<" / "<<month1<<" / "<<year1<<"\n";
    cout<<"\t To : ";
    cout<<day2<<" / "<<month2<<" / "<<year2;
    ti[0]=day1;
    ti[1]=month1;
    ti[2]=year1;
    ti[3]=day2;
    ti[4]=month2;
    ti[5]=year2;
    durd=day(ti,6);
    h=(sumwe/7)*durd;
    cout<<"\n Time duration : \n";
    cout<<"\t\t In days : "<<durd;
    cout<<"\n\t\t In hours : "<<h;
    textcolor(RED+BLINK);
    cprintf("\r\n\n\n Press any key to continue!. ");
    getch();
    char naday[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    start:clrscr();textcolor(1);
    cprintf("\r__________________________________________________________\n\n");
    cprintf("\r\n");
    textcolor(14);
    cout<<"\t\t\t";
    cprintf("WELCOME TO TIME SHEDULER SYSTEM\n");
    cprintf("\r\n");textcolor(1);
    cprintf("\r__________________________________________________________\r\n\n");
    textcolor(15);
    cout<<"\t";cprintf("1 : Time schedule of subject\r\n");
    cout<<"\t";cprintf("2 : Time schedule of lesson\r\n");
    cout<<"\t";cprintf("3 : Update account \r\n");
    cout<<"\t";cprintf("4 : Help\r\n");
    cout<<"\t";cprintf("5 : Main menu\r\n");
    textcolor(RED);
    cout<<"\t\t";cprintf("\nSelect your option : ");
    fflush(stdin);
    option=getche();
    if (option=='1')
    {
	for(x=0;x<ns;x++)subh[x]=((weigs[x]*h)/100);
	textcolor(14);
	clrscr();
	cprintf("\n TIME SCHEDULE OF SUBJECT \r\n");
	textcolor(1);
	cprintf("____________________________________________________________\r\n");
	textcolor(2);
	cout<<"\n";
	for(x=0;x<ns;x++)
	    for(y=0;y<7;y++)
		subod[x][y]=(hr[y]*weigs[x])/100;
	for(x=0;x<ns;x++)
	{
	    cout<<"\t"<<x+1<<" : ";
	    cprintf(nsub[x]);
	    cout<<" "<<subh[x]<<"hr\r\n";
	}
	cout<<"\n\nLearn at least on :";
	for(x=0;x<ns;x++)
	    subh[x]=((weigs[x]*h)/100);
	for(y=0;y<7;y++)
	{
	    cout<<"\n";
	    cprintf(naday[y]);
	    cout<<" : ";
	    for(x=0;x<ns;x++)
		cout<<"\t"<<nsub[x]<<" : "<<subod[x][y]<<" ";
	}
	getche();
	goto start;
    }
    else if(option=='2')
    {
	for(x=0;x<ns;x++)subh[x]=((weigs[x]*h)/100);/* to find available hours of each subject */
	for(x=0;x<ns;x++)
	    for(y=temp[x];y<nl[x];y++)
		lesh[x][y]=((subh[x]*weig[x][y])/mar[x]);/*to find available hour for each lesson */
	for(x=0;x<ns;x++)
	    for(y=0;y<7;y++)
		subod[x][y]=(hr[y]*weigs[x])/100;/*to find time of one subject in a day */
	clrscr();
	textcolor(14);
	cprintf("\n TIME SCHEDULE OF LESSONS \r\n");
	textcolor(9);
	cprintf("\n_______________________________________________________________________\r\n");
	textcolor(2);
	for(y=0;y<ns;y++)
	{
	    cout<<"\n";
	    cprintf(nsub[y]);
	    cout<<" : \r\n";
	    for(z=temp[y];z<nl[y];z++)
	    {
		if(lesh[y][z]<0)
		    lesh[y][z]=-1*lesh[y][z];
		cout<<"\t"<<z+1<<" : "<<lesson[y][z]<<" "<<lesh[y][z]<<"hr\n";
	    }
	    getche();
	}
	goto start;
    }
    else if(option=='3')
    {
	clrscr();
	textcolor(14);
	cprintf("\n UPDATE ACCOUNT \r\n\n");
	cout<<"Please enter data : \n";
	cout<<"\tDay :";cin>>iday;
	cout<<"\tMonth : ";cin>>imonth;
	cout<<"\tYear : ";cin>>iyear;
	cout<<"How much lesson you have completed in :\n";
	for(x=0;x<ns;x++)
	{
	    cout<<"\t"<<x+1<<" : ";
	    cprintf(nsub[x]);
	    cout<<"(from "<<lesson[x][temp[x]]<<") : ";
	    cin>>comp[x];
	}
	for(x=0;x<ns;x++)
	    for(y=temp[x];y<comp[x];y++)/*user completed time*/
		addh=addh+lesh[x][y];
	for(x=0;x<ns;x++)
	{
	    temp2[x]=temp[x];
	    temp2[x]=temp2[x]+comp[x];
	    temp[x]=temp2[x];
	}
	for(x=0;x<ns;x++)
	{
	    remark[x]=0;
	    for(y=0;y<temp[x];y++)
		remark[x]=remark[x]+weig[x][y];
	}
	for(x=0;x<ns;x++)
	    mar[x]=dmar[x]-remark[x];
	for(x=0;x<ns;x++)
	    subh[x]=((weigs[x]*h)/100);/* to find available hours of each subject*/
	for(x=0;x<ns;x++)
	    for(y=temp[x];y<nl[x];y++)
		lesh[x][y]=((subh[x]*weig[x][y])/mar[x]);

	td[0]=day1;
	td[1]=month1;
	td[2]=year1;
	td[3]=iday;
	td[4]=imonth;
	td[5]=iyear;
	diff=day(td,6);
	ctime=(sumwe/7)*diff;/*completed hour */
	day1=iday;
	month1=imonth;
	year1=iyear;
	ti[0]=day1;
	ti[1]=month1;
	ti[2]=year1;
	ti[3]=day2;
	ti[4]=month2;
	ti[5]=year2;
	durd=day(ti,6);
	if(addh>ctime)
	{
	    cout<<"Good Job you exceed your time duration, there remain ";
	    remin=addh-ctime;
	    cout<<remin<<" hr!. \n Press any key to update...";
	    sumwe=0;
	    for(int i=0;i<7;i++)
		sumwe=sumwe+hr[i];
	    h=(sumwe/7)*durd;
	    getche();
	    goto start;
	}
	else
	{
	    remin=ctime-addh;
	    cout<<"Your performance is good, but there is a lack of "<<remin<<"hr ";
	    cout<<"you have to option to overcome this time lack\n\t 1: Add "<<remin<<"hr in ";
	    cout<<"your learning time \n\t 2: Rearrange time schedule \n Choose your option : ";
	    fflush(stdin);
	    opt=getche();
	    if (opt=='1')
	    {
		cout<<"Add time : -";
		cout<<"\n\t Sunday : "<<hr[0]<<"+";cin>>hr2[0];
		cout<<"\t Monday : "<<hr[1]<<"+";cin>>hr2[1];
		cout<<"\t Tuesday : "<<hr[2]<<"+";cin>>hr2[2];
		cout<<"\t Wednesday : "<<hr[3]<<"+";cin>>hr2[3];
		cout<<"\t Thursday : "<<hr[4]<<"+";cin>>hr2[4];
		cout<<"\t Friday : "<<hr[5]<<"+";cin>>hr2[5];
		cout<<"\t Saturday : "<<hr[6]<<"+";cin>>hr2[6];
		for(x=0;x<7;x++)
		    hr[x]=hr[x]+hr2[x];
		sumwe=0;
		for(int i=0;i<7;i++)
		    sumwe=sumwe+hr[i];
		h=(sumwe/7)*durd;
		cout<<"\n\nPress any key to update....";
	    }
	    else if (opt=='2')
	    {
		sumwe=0;
		for(int i=0;i<7;i++)
		    sumwe=sumwe+hr[i];
		h=(sumwe/7)*durd;
	    }
	}
	getche();
	goto start;
    }
    else if(option=='4')
    {
	clrscr();

	textcolor(1);
	cprintf("\r\n");
	cout<<"\t\t\t\tHELP";
	printf("\r\n______________________________________________________________________\r\n\n");
	textcolor(2);
	cprintf("\r\n\n 1: Time schedule of subjects : \r\n :: It gives an idea about hours that that divided for your subject and for day");
	cprintf("\r\n 2: Time schedule of lessons : \r\n:: It gives divided time of each lesson in you time duration");
	cprintf("\r\n 3: Update :\r\n:: It's the main feature of STMS, it provide a dynamic arrangement for your        study time ");
	textcolor(RED);cout<<"\t\t";cprintf("\n Press any key to continue ...");
	getche();
	goto start;
    }
    else if(option=='5');/*may wrong */
    else goto start;

}


void base::help()
{
    clrscr();
    textcolor(1);
    printf("\r________________________________________________________________________________\r\n\n");
    cout<<"\t\t\t\t";
    textcolor(12);
    cprintf("HELP\r\n");
    textcolor(1);
    cprintf("\r________________________________________________________________________________\r\n\n");
    textcolor(2);
    cprintf("\r\n\n 1: How can create a new account ?\r\n ans: Press 1 t create new account, then gives your personal data, password           and course details.");
    cprintf("\r\n 2: How cam give Password ? \r\n ans: You can give 0 to 9 digit number as password in step 1/3 press 2,               then give your password");
    cout<<"\r\n\n\t\t";
    textcolor(4);
    cprintf("** Warning : Password must in digit **\r\n");
    textcolor(RED);
    cout<<"\t\t";
    cprintf("\n Press any key to continue...");
    getche();
    welcome();

}

void base::about()
{
    clrscr();
    textcolor(10);
    cprintf("\r________________________________________________________________________________\r\n\n");
    cout<<"\t\t\t\t";
    textcolor(12);
    cprintf("ABOUT\r\n");
    textcolor(1);
    cprintf("\r________________________________________________________________________________\r\n\n");
    textcolor(2);
    cprintf("It is a console application created for time management. It will be help for student who ready to a systematic learning, it also give important instruction and warning when it required. It provides time table fir your subjects about a week and give instruction about your goal duration.\r\n");
    cout<<"\r\n\n";
    textcolor(RED);
    cprintf("\r\nPress ay key to continue...");
    fflush(stdin);
    ch=getche();
    switch(ch){
    case '1':
	welcome();break;
    default:
	welcome();break;
    }
}

int base::day(int ti[],int)/* for calculating days*/
{
    int s1,sum2,con,add,s2,con2,add2,sum;
    if(ti[2]%4!=0)
    {
	if(ti[1]==1)s1=0;
	else if(ti[1]==2)s1=31;
	else if(ti[1]==3)s1=59;
	else if(ti[1]==4)s1=90;
	else if(ti[1]==5)s1=120;
	else if(ti[1]==6)s1=151;
	else if(ti[1]==7)s1=181;
	else if(ti[1]==8)s1=212;
	else if(ti[1]==9)s1=243;
	else if(ti[1]==10)s1=273;
	else if(ti[1]==11)s1=304;
	else if(ti[1]==12)s1=335;
    }
    if(ti[2]%4==0)
    {
	if(ti[1]==1)s1=0;
	else if(ti[1]==2)s1=31;
	else if(ti[1]==3)s1=60;
	else if(ti[1]==4)s1=91;
	else if(ti[1]==5)s1=121;
	else if(ti[1]==6)s1=152;
	else if(ti[1]==7)s1=182;
	else if(ti[1]==8)s1=213;
	else if(ti[1]==9)s1=244;
	else if(ti[1]==10)s1=274;
	else if(ti[1]==11)s1=305;
	else if(ti[1]==12)s1=336;
    }
    if(ti[5]%4!=0)
    {
	if(ti[4]==1)s2=0;
	else if(ti[4]==2)s2=31;
	else if(ti[4]==3)s2=59;
	else if(ti[4]==4)s2=90;
	else if(ti[4]==5)s2=120;
	else if(ti[4]==6)s2=151;
	else if(ti[4]==7)s2=181;
	else if(ti[4]==8)s2=212;
	else if(ti[4]==9)s2=243;
	else if(ti[4]==10)s2=273;
	else if(ti[4]==11)s2=304;
	else if(ti[4]==12)s2=335;
    }
    else if(ti[5]%4==0)
    {
	if(ti[4]==1)s2=0;
	else if(ti[4]==2)s2=31;
	else if(ti[4]==3)s2=60;
	else if(ti[4]==4)s2=91;
	else if(ti[4]==5)s2=121;
	else if(ti[4]==6)s2=152;
	else if(ti[4]==7)s2=182;
	else if(ti[4]==8)s2=213;
	else if(ti[4]==9)s2=244;
	else if(ti[4]==10)s2=274;
	else if(ti[4]==11)s2=305;
	else if(ti[4]==12)s2=336;
    }
    con=ti[2]-2014;
    add=con/3;
    sum=((con*365)+(s1+add+ti[0]));
    con2=ti[5]-2014;
    add=con2/3;
    sum2=((con2*365)+(add+s2+ti[3]));
    dur=sum2-sum+1;
    return(dur);

}


void base::getdata()
{
    clrscr();
    sumwe=0;
    float markc[50];
    textcolor(12);
    cprintf("step 1/4 \r\n\n");
    cout<<"Enter user name : ";gets(name);
    cout<<"Enter your last name : ";gets(name1);
    cout<<"Enter password in digits : ";cin>>pword;
    cout<<"Method of preparation : ";cin>>mpre;
    textcolor(15);
    cprintf("Set your Goal \r\n\n");
    cprintf("******************* Time duartion *****************\r\n\n");
    cout<<"\t From: :- \n";
    cout<<"\t\t Day: ";cin>>day1;
    cout<<"\t\t Month :";cin>>month1;
    cout<<"\t\t Year(4 digit) : ";cin>>year1;
    cout<<"\t To :-\n";
    cout<<"\t\t Day: ";cin>>day2;
    cout<<"\t\t Month :";cin>>month2;
    cout<<"\t\t Year(4 digit) : ";cin>>year2;
    clrscr();
    textcolor(12);
    cprintf("\r step 2/4 \r\n\n");
    cout<<"How much time (in hour) you have to spent for learning in :- ";
    cout<<"\n\t Sunday : ";cin>>hr[0];
    cout<<"\t Monday : ";cin>>hr[1];
    cout<<"\t Tuesday : ";cin>>hr[2];
    cout<<"\t Wednesday : ";cin>>hr[3];
    cout<<"\t Thursday : ";cin>>hr[4];
    cout<<"\t Friday : ";cin>>hr[5];
    cout<<"\t Saturday : ";cin>>hr[6];
    for(int i=0;i<7;i++)
	sumwe+=hr[i];
    cout<<"Average = "<<sumwe/7;
    clrscr();
    textcolor(12);
    cprintf("\r step 3/4 \r\n\n");
    textcolor(13);
    cprintf("Course settings :");
    cout<<"\r\nEnter name of course :";gets(course);
    cout<<"Enter number of subject : ";cin>>ns;
    beg:
	cout<<"\n\n";
	for(x=0;x<ns;x++)
	{
	    int conf[50];
	    conf[0]=100;
	    cout<<"Enter name of subject"<<x+1<<" : ";
	    gets(nsub[x]);
	    cout<<"Enter weight of subject (in "<<conf[x]<<" ) :";
	    cin>>weigs[x];
	    conf[x+1]=conf[x]-weigs[x];
	    cout<<"Enter total mark of subject :";
	    cin>>mar[x];
	    dmar[x]=mar[x];
	    cout<<"No. Lesson : ";
	    cin>>nl[x];
	    cout<<"\n\n";
	}
	clrscr();
	textcolor(12);
	cprintf("step 4/4 \r\n\n");
	cprintf("\r\n Enter name of lesson & marks :\n");
	textcolor(1);
	cprintf("\r__________________________________________________________\r\n\n");
	for(y=0;y<ns;y++)
	{
	    cout<<"\t"<<nsub[y]<<":\n";
	    markc[y]=mar[y];
	    for(z=0;z<nl[y];z++)
	    {
		temp[x]=0;
		cout<<"\t\t Lesson "<<z+1<<" : ";gets(lesson[y][z]);
		cout<<"\t\t Mark (in "<<markc[y]<<" ) : ";
		cin>>weig[y][z];
		markc[y]=markc[y]-weig[y][z];
	    }
	}
	textcolor(RED);
	cprintf("\n Your account is created, Press any key to continue...\r\r");
	getche();

}

void base::End()
{
    clrscr();
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t";
    textcolor(3);
    cprintf(" TIME IS");cout<<"\r\n\t";
    cprintf(" TOO SLOW FOR THOSE WHO WAITES, TOO SHIFT FOR THOSE WHO FEAR, ");cout<<"\r\n\t";
    cprintf("TOO LONG FOR THOSE WHO GRIEVE, TOO SHORT FOR THOSE WHO REJOICE;");cout<<"\r\n\t\t";
    cprintf("BUT FOR THOSE WHO LOVE, TIME IS ETERNINTY.");
    textcolor(GREEN);
    cout<<"\r\n\n\n\n\t\t    ";cprintf("THANK YOU FOR USING THIS SOFTWARE");
    delay(3000);
    exit(0);
}

int main()
{
    WELCOME();
    welcome();
    getch();
    return 0;
}




void WELCOME()
{
    clrscr();
    cout<<"\n\n\n\n\n\n";
    textcolor(2);
    cout<<"\t";
    cprintf("************************************************************\r\n");
    textcolor(14);
    cout<<"\t\t";
    cprintf("**WELCOME TO STUDENT TIME MANAGEMENT SYSTEM **\r\n");
    textcolor(2);
    cout<<"\t";
    cprintf("*************************************************************\r\n");
    textcolor(3);
    cout<<"\n\n\t\t\t";
    cprintf("A DREAM BECOMES A GOAL ");cout<<"\n\t";
    cprintf("WHEN RIGHT ACTION IS TAKEN TOWARDS IT'S ACHIEVEMENT.\r");cout<<"\n\t";
    cprintf("AND THE PROGRESS IS EASIER WHEN IT IS PERFECTLY TIMED,\r");cout<<"\n\t\t\t";
    cprintf("CHECKED AND MEASURED");
    delay(3000);
    clrscr();

}


int welcome()
{
    start:
    clrscr();
    char choice;
    long rn;char ans='y',found='n';
    long pos;
    textcolor(1);
    cprintf("\r_________________________________________________________________________\n\n");
    cprintf("\r\n");textcolor(14);
    cout<<"\t\t\t";
    cprintf("STUDENT TIME MANAGEMENT SYSTEM\n");
    cprintf("\r\n");textcolor(1);
    cprintf("\r_________________________________________________________________________\n\n");
    cprintf("\r\n");textcolor(2);
    cprintf("Welcome to STMS monitor, it is created for student, it's help to achieve goal of hard working students. STMS calculates the learning time of student and it provide asystematic time schedule for their subjects, lessons and also gives the important instruction and warning. ");
    cout<<"\n";
    cprintf("---------------------------------------------------------------------------\n");
    cprintf("\r");
    cout<<"\t";textcolor(15);
    cprintf("1 - Create account");
    cprintf("   2 - Open account\r\n");
    cout<<"\t";
    cprintf("3 - Help             4 - About \r\n");
    cout<<"\t";
    cprintf("5 - Exit\r\n");
    cout<<"\t\t";
    textcolor(RED);cprintf("\n Enter your choice ( 1 -5 ):");
    fflush(stdin);
    choice=getche();
    if(choice=='1')
    {
	ofstream fo("stms.dat",ios::app);
	while(ans=='y')
	{
	    b.getdata();
	    fo.write((char*)&b,sizeof(b));
	    ans='n';
	}fo.close();b.open();
    }
    else if (choice=='2')
    {
	fstream fi("stms.dat",ios::in||ios::out);
	cout<<"\n\tPlease enter you password : ";
	cin>>rn;
	while(!fi.eof())
	{
	    pos=fi.tellg();
	    fi.read((char*)&b,sizeof(base));
	    if (b.getrno()==rn)
	    {
		b.open();
		fi.seekg(pos);
		fi.write((char*)&b,sizeof(base));
		found='y';
		break;
	    }
	}
	fi.close();
	welcome();
	if(found=='n')
	{
	    textcolor(RED);
	    cprintf("Account is not found in database!\r\n");
	    welcome();
	}
    }
    else if(choice=='3')b.help();
    else if(choice=='4')b.about();
    else if(choice=='5')b.End();
    else goto start;
    return 0;
}




