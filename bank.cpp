#include<iostream>
#include<string>
#include<limits>
#include<fstream>

namespace bnk
{
	enum class acc_type{ saving = 1, current };
	
	struct bank_column{
		int acc_no;
		char name[50];
		double balance;
		acc_type type;
	};

	class bank_op{
		public:
			virtual void search_acc() = 0;
			virtual void check_balance() = 0;
			virtual ~bank_op() {}
	};

	class admin : public bank_op
	{
		public:	
			void write_data(bank_column bc){
				std::ofstream file("bank.dat",std::ios::binary | std::ios::app);
				file.write((char*)&bc, sizeof(bc));
				file.close();
			}
			
			bank_column read_data(){
				bank_column bc;
				
				std::ifstream file("bank.dat",std::ios::binary);
				file.read((char*)&bc, sizeof(bc));
				file.close();

				return bc;
			}
			
			void display(bank_column bc){
				//std::cout <<"-----------USER DATA-----------"<< std::endl;
				std::cout <<"-------------------------------"<< std::endl;
				std::cout <<"Acc name    : "<< bc.name << std::endl;
				std::cout <<"Acc number  : "<< bc.acc_no << std::endl;
				std::cout <<"Acc balance : "<< bc.balance << std::endl;
				if(bc.type == acc_type::saving)
					std::cout <<"Acc type    : Saving\n";
				else
					std::cout <<"Acc type    : Current\n";
			}
			
			void create_acc() {
				std::cout <<"create account\n";
				bank_column acc;

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<"Enter name : ";
				std::cin.getline(acc.name, 49);
				
				std::cout <<"Enter balance : ";
				std::cin >> acc.balance;
				
				int type;
				std::cout <<"1.saving\t2.current\nEnter Acc type : ";
				std::cin >> type;

				if(type == 1)	
					acc.type = acc_type::saving;
				else	
					acc.type = acc_type::current;
				
				write_data(acc);

				std::cout <<"Account created successfully\n";
			}
			void delete_acc() {
				std::cout <<"Delete account\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
				
			}
			void update_acc() {
				std::cout <<"Update acc\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
			}
			void check_balance() override {
				std::cout <<"check balance\n";

			}
			void search_acc() override {
				std::cout <<"Search acc\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
			}
			void display_all_acc() {	
				bank_column bc;
				
				std::ifstream file("bank.dat",std::ios::binary);

				std::cout <<"----------ALL ACCOUNTS---------\n";
				while(file.read((char*)&bc,sizeof(bc))){
					/*std::cout <<"Acc No   : "<<bc.acc_no << std::endl;;
					std::cout <<"Name     : "<<bc.name << std::endl;;
					std::cout <<"Balance  : "<<bc.balance << std::endl;;
					if(bc.type == acc_type::saving)
						std::cout <<"Acc type : Saving\n";
					else
						std::cout <<"Acc type : Current\n";*/
					display(bc);
				}
				
				file.close();
			}
	};

	class user : public bank_op
	{
		public: 
			void send_money() {
				std::cout <<"---------TRANSFER MONEY--------\n";
				long int acn1, acn2, bal;

				std::cout <<"Enter Sender Acc no   : ";
				std::cin >> acn1;
				std::cout <<"Enter Receiver Acc no : ";
				std::cin >> acn2;
				std::cout <<"Enter Amount to send  : ";
				std::cin >> bal;
				std::cout <<"-------------------------------\n";	
			}
			void deposit_money() {
				
			}
			void check_balance() override {
				
			}
			void search_acc() override {

			}
	};
};

int main()
{
	bnk::admin adm;
	//bnk::user usr;

	std::cout <<"-------------------------------"<< std::endl;
	std::cout <<"            WELCOME            "<< std::endl;
	
	while(true){
		int op;
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<"1.Create Acc\t2.Update Acc\n3.Search Acc\t4.Delete Acc\n5.Display all\t6.Exit\n";
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<"Enter option : ";
		std::cin >> op;
		std::cout <<"-------------------------------"<< std::endl;
		
		switch(op)
		{
			case 1 : adm.create_acc();	break;
			case 2 : adm.update_acc();	break;
			case 3 : adm.search_acc();	break;
			case 4 : adm.delete_acc();	break;
			case 5 : adm.display_all_acc();	break;
			case 6 : exit(0);
			default: std::cout <<"  wrong option! Enter again!\n";
		}
	}
}

















