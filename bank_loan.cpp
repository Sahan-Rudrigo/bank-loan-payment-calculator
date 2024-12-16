#include<iostream>
#include<cmath>
#include <fstream>


using namespace std;

string Name;
int Age,Income,Option,RepayPeriod;
double Amount;

void Vehical(){
    cout<< "Vehicle :: \n\t\t Max Loan amount = 1,000,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  14%\n\n";}

void Housing(){
    cout<< "Housing :: \n\t\t Max Loan amount = 2,500,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  8%\n\n";}

void Education(){
   cout<< "Education :: \n\t\t Max Loan amount = 1,500,000LKR\n\t\t Max Repay Period =284 months\n\t\t Interest Rate =  6%\n\n";}

 void Senior_Citizen(){
   cout<< "senior Citizen :: \n\t\t Max Loan amount = 500,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  4.5%\n\n";}

 void Personalloan1(){
   cout<< "Personalloan1 :: \n\t\t Max Loan amount = 2,000,000 LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  14.5%\n\n";}

void Personalloan2(){
   cout<< "Personalloan2 :: \n\t\t Max Loan amount = 3,000,000 LKR\n\t\t Max Repay Period =84 months\n\t\t Interest Rate =  16.2%\n\n";}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Vehical(ofstream& outFile) {
    outFile << "Vehicle :: \n\t\t Max Loan amount = 1,000,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  14%\n\n";
}

void Housing(ofstream& outFile) {
    outFile << "Housing :: \n\t\t Max Loan amount = 2,500,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  8%\n\n";
}
void Education(ofstream& outFile) {
    outFile << "Education :: \n\t\t Max Loan amount = 1,500,000LKR\n\t\t Max Repay Period =284 months\n\t\t Interest Rate =  6%\n\n";
}
void Senior_Citizen(ofstream& outFile) {
    outFile << "senior Citizen :: \n\t\t Max Loan amount = 500,000LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  4.5%\n\n";
}
void Personalloan1(ofstream& outFile) {
    outFile << "Personalloan1 :: \n\t\t Max Loan amount = 2,000,000 LKR\n\t\t Max Repay Period =60 months\n\t\t Interest Rate =  14.5%\n\n";
}
void Personalloan2(ofstream& outFile) {
    outFile << "Personalloan2 :: \n\t\t Max Loan amount = 3,000,000 LKR\n\t\t Max Repay Period =84 months\n\t\t Interest Rate =  16.2%\n\n";
}


void Calculate( float amount, int Repayperiod, float AIR) {
    int n = Repayperiod * 12;
    float MIR = AIR / 1200; 

   float D = (pow(1 + MIR, n) - 1) / (MIR * pow(1 + MIR, n));


    float MonthlyPayment = amount / D;

   cout<<"Monthly Repay Amount :: "<< MonthlyPayment<<"LKR"<<endl;
   float TotalPay;
   TotalPay = MonthlyPayment * n;
   cout<< "Total Amount of money You Pay :: "<< TotalPay<<"LKR"<<endl;
   float BankIncome;
   BankIncome = TotalPay - amount;
   cout<< "Total Amount Interest By Bank :: "<<BankIncome<<"LKR"<<endl;


}


void printtable(ofstream &writeFile,float amount,int Repayperiod ,float AIR){
    int n = Repayperiod * 12;
    float MIR = AIR / 1200; 

   float D = (pow(1 + MIR, n) - 1) / (MIR * pow(1 + MIR, n));

    float MonthlyPayment = amount / D;
    float repaid =0;
    float Interest=0;
    

        writeFile<<"|\tMonth\t|\tRemaining Loan Amount\t|\tInterest\t|\tRepaid Loan Amount|"<<endl;
        writeFile<<"\t*************************************************************************************\n\n";
        for (int i = 0 ;i<n;i++){

            writeFile<<"\t"<<i+1<<"\t\t\t";
            amount = amount - repaid;
            writeFile<<amount<<"\t\t\t";
            Interest = amount*MIR;
            writeFile<<Interest<<"\t\t\t";
            repaid = MonthlyPayment-Interest;
            writeFile<<repaid<<endl;
        }

        writeFile<<endl;


    

}

int main(){

    while(true){

cout<< "\n***********************************************\n";
cout<< "Enter Your Name :: ";
cin>>Name;

cout<< "\n*********Hello "<<Name<<". Welcome*********\n\nThere are six Loan options You can apply\n******************************************\n\nOption 1 -> Vehicle loan\nOption 2 -> Housing loan \nOption 3 -> Education loan\nOption 4 -> Senior Citizen loan\nOption 5 -> Personal loan1\nOption 6 -> Personal loan2 \n\n";
cout<< "Please Provide your Age and income details Before Select your Loan\n********************************************************\n\n";
cout<< "Enter Your Age :: ";
cin>>Age;
cout<< "Enter Your Monthly Income :: ";
cin>>Income;
cout<< "\n***********************************************\n";

if(Age <18 ){

    cout<< "You cannot Apply to any loan.Your Age should greater than 18 ";
   
    return main();
}
 

else if( Income<35000){
    cout<< "You cannot Apply to any loan.Your Income should be greater than 35000LKR ";
    return main();
}

else if((Age>=18 && Age<25)&&(Income>45000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 -> canot apply"<<endl;
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;

    
}
else if((Age>=25 && Age<30 )&&(Income>=45000 && Income<100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 ->";
    Education();
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;

    
}

else if((Age>=25 && Age<30 )&&(Income>=100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 ->";
    Housing();
    cout<< "option 3 ->";
    Education();
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;

    
}

else if((Age>=30 && Age<=35)&&(Income>=45000 && Income<100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 ->";
    Education();
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> ";
    Personalloan1();
    cout<< "option 6 -> "; 
    Personalloan2();
   
}

else if((Age>=30 && Age<=35)&&(Income>=100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> ";
    Housing();
    cout<< "option 3 ->";
    Education();
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> ";
    Personalloan1();
    cout<< "option 6 -> "; 
    Personalloan2();
   
}

else if((Age>35 && Age<=55 )&&(Income>=45000 && Income<100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 -> canot apply"<<endl;
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;

   
}
else if((Age>35 && Age<=55 )&&(Income>=100000) ){

    cout<<"option 1 ->";
    Vehical();
    cout<< "option 2 -> ";
    Housing();
    cout<< "option 3 ->canot apply"<<endl;;
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> ";
    Personalloan1();
    cout<< "option 6 -> "; 
    Personalloan2();
   
}
else if(Age>55 && Age<=60 ){

    cout<< "option 1 -> canot apply"<<endl;
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 -> canot apply"<<endl;
    cout<< "option 4 -> canot apply"<<endl;
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;
    cout<< "Sorry,Your age is not Valid for loan.You cannot Apply to any loan.";
   
}
else if(Age>=60&&Income>=35000){
    cout<< "option 1 -> canot apply"<<endl;
    cout<< "option 2 -> canot apply"<<endl;
    cout<< "option 3 -> canot apply"<<endl;
    cout<< "option 4 ->" ;
     Senior_Citizen();
    cout<< "option 5 -> canot apply"<<endl;
    cout<< "option 6 -> canot apply"<<endl;
   
   
}

cout<<endl<<endl;

cout<< "Select Your Option :: ";
cin>>Option;

cout<< "Enter  amount of money you wish to borrow(Do not exceed maximum amount) :: ";
cin>>Amount;

cout<< "Enter possible Repay Period(Do not exceed maximum period(Years) ::";
cin>> RepayPeriod;

switch (Option){

    case 1: 
       Calculate(Amount,RepayPeriod,14);break;
    case 2: 
       Calculate(Amount,RepayPeriod,8);break;
    case 3: 
       Calculate(Amount,RepayPeriod,6);break;
    case 4: 
       Calculate(Amount,RepayPeriod,4.5);break;
    case 5: 
       Calculate(Amount,RepayPeriod,14.5);break;
    case 6: 
       Calculate(Amount,RepayPeriod,16.2);break;

    default:
        cout<< "There is no any "<<Option<<"th option";break;
    
      
}
 string fileName = Name + ".txt";
 ofstream myfile;
myfile.open (fileName);
switch (Option){

    case 1:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Vehical(myfile);
         printtable(myfile,Amount,RepayPeriod,14);break;
        
    case 2:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Housing(myfile);
         printtable(myfile,Amount,RepayPeriod,8);break;
    case 3:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Education(myfile);
         printtable(myfile,Amount,RepayPeriod,6);break;

    case 4:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Senior_Citizen(myfile);
         printtable(myfile,Amount,RepayPeriod,4.5);break;
    
    case 5:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Personalloan1(myfile);
         printtable(myfile,Amount,RepayPeriod,14.5);break;
    
    case 6:
         myfile<< "Coustomer Name :: Mr/Mrs "<<Name<<endl;
         myfile<<"Your Loan Details are here :: \n";
         Personalloan2(myfile);
         printtable(myfile,Amount,RepayPeriod,16.2);break;

    default:
         myfile << "There is no any "<<Option<<"th option";break;

}
myfile.close();}
 


}

