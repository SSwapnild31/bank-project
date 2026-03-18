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
			virtual void display(bank_column) = 0;
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
			
			void create_acc() {
				std::cout <<" Creating Account\n";
				bank_column acc;

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<" Enter name : ";
				std::cin.getline(acc.name, 49);
				
				std::cout <<" Enter balance : ₹.";
				std::cin >> acc.balance;
				
				int type;
				std::cout <<" 1.saving\t2.current\n Enter Acc type : ";
				std::cin >> type;

				if(type == 1)	
					acc.type = acc_type::saving;
				else	
					acc.type = acc_type::current;
				
				write_data(acc);

				std::cout <<" Account created successfully\n";
			}

			void delete_acc() {
				std::cout <<" Deleting account\n";
				
				int number;
				std::cout <<" Enter acc number : ";
				std::cin >> number;
				
			}

			void update_acc() {
				std::cout <<" Updating account\n";
				
				int number;
				std::cout <<" Enter acc number : ";
				std::cin >> number;
			}

			void search_acc() override {
				bank_column bc;
				long int acn;
				std::cout <<" Enter Acc no : ";
				std::cin >> acn;
				
				std::ifstream file("bank.dat",std::ios::binary);

				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Record Found ->\n";
						display(bc);

						file.close();
						return;
					}
				}
				
				std::cout <<" Acc not present/wrong number!\n";
			}

			void check_balance() override {
				bank_column bc;
				long int acn;
				
				std::cout <<" Enter Acc no : ";
				std::cin >> acn;
				
				std::ifstream file("bank.dat",std::ios::binary);
				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Acc Balance ->\n";
						std::cout <<" ..........................\n";
						std::cout <<" Acc number  : "<< bc.acc_no << std::endl;
						std::cout <<" Acc balance : "<< bc.balance <<" ₹."<< std::endl;
						
						file.close();
						return;
					}
				}
				
				std::cout <<" Acc not present/wrong number!\n";
			}
			
			void display_all_acc() {	
				bank_column bc;
				
				std::ifstream file("bank.dat",std::ios::binary);
				
				std::cout <<" All Records -> \n";
					
				while( file.read((char*)&bc,sizeof(bc)) ){
					display(bc);
				}
				
				file.close();
			}

			void display(bank_column bc){
				std::cout <<" ..........................\n";	
				std::cout <<" User name   : "<< bc.name << std::endl;
				std::cout <<" Acc number  : "<< bc.acc_no << std::endl;
				std::cout <<" Acc balance : "<< bc.balance <<" ₹."<< std::endl;
				if(bc.type == acc_type::saving)
					std::cout <<" Acc type    : Saving\n";
				else
					std::cout <<" Acc type    : Current\n";
			}
	};

	class user : public bank_op
	{
		public: 	
			void send_money() {
				std::cout <<" Transfer Money ->\n";
				long int acn1, acn2, bal;

				std::cout <<" Enter Sender Acc no   : ";
				std::cin >> acn1;
				std::cout <<" Enter Receiver Acc no : ";
				std::cin >> acn2;
				std::cout <<" Enter Amount to send  : ₹.";
				std::cin >> bal;
				//std::cout <<"-------------------------------\n";	
			}
			
			void deposit_money() {
				std::cout <<" Deposit Money ->\n";
				long int acn1, acn2, bal;

				std::cout <<" Enter Sender Acc no   : ";
				std::cin >> acn1;
				std::cout <<" Enter Receiver Acc no : ";
				std::cin >> acn2;
				std::cout <<" Enter Amount to send  : ₹.";
				std::cin >> bal;
				//std::cout <<"-------------------------------\n";		
			}

			void check_balance() override {
				bank_column bc;
				long int acn;
				
				std::cout <<" Enter Acc no : ";
				std::cin >> acn;
				
				std::ifstream file("bank.dat",std::ios::binary);

				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Acc Balance ->\n";
						std::cout <<" ..........................\n";
						std::cout <<" Acc number  : "<< bc.acc_no << std::endl;
						std::cout <<" Acc balance : "<< bc.balance <<" ₹."<< std::endl;
						
						file.close();
						return;
					}
				}
				
				std::cout <<" Acc not present/wrong number!\n";
			}
			
			void search_acc() override {
				bank_column bc;
				long int acn;
				
				std::cout <<" Enter Acc no : ";
				std::cin >> acn;
				
				std::ifstream file("bank.dat",std::ios::binary);
				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Record Found ->\n";
						display(bc);
						file.close();
						return;
					}
				}
				
				std::cout <<" Acc not present/wrong number!\n";
			}

			void display(bank_column bc){
				std::cout <<" ..........................\n";
				std::cout <<" User name   : "<< bc.name << std::endl;
				std::cout <<" Acc number  : "<< bc.acc_no << std::endl;
				std::cout <<" Acc balance : "<< bc.balance <<" ₹."<< std::endl;
				if(bc.type == acc_type::saving)
					std::cout <<" Acc type    : Saving\n";
				else
					std::cout <<" Acc type    : Current\n";
			}
	};
};

int main()
{
	bnk::admin adm;
	bnk::user usr;

	std::cout <<"-------------------------------"<< std::endl;
	std::cout <<"          | WELCOME |          "<< std::endl;
	std::cout <<"-------------------------------"<< std::endl;


	while(true){	
		int ch;
		std::cout <<"    1.Admin  2.User  3.Exit\n";
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<" Enter option : ";
		std::cin >> ch;

		switch(ch){
			case 1 :
				while(true){
					int op;
					std::cout <<"-------------------------------"<< std::endl;
					std::cout <<" 1.Create Record\t2.Update Record\n 3.Search Record\t4.Delete Record\n 5.Check balalance\t6.Display Records\n 7.Main menu\n";
					std::cout <<"-------------------------------"<< std::endl;
					std::cout <<" Enter option : ";
					std::cin >> op;
					std::cout <<"-------------------------------"<< std::endl;

					if(op == 7) break;

					switch(op){
						case 1 : adm.create_acc();	break;
						case 2 : adm.update_acc();	break;
						case 3 : adm.search_acc();	break;
						case 4 : adm.delete_acc();	break;
						case 5 : adm.check_balance();	break;
						case 6 : adm.display_all_acc();	break;
						default: std::cout <<" wrong option! Enter again!\n";
					}
				}	
				break;
			case 2 :
				while(true){
					int op;
					std::cout <<"-------------------------------"<< std::endl;
					std::cout <<" 1.Search Acc\t2.Check bal\n 3.Send money\t4.Deposit money\n 5.Main menu\n";
					std::cout <<"-------------------------------"<< std::endl;
					std::cout <<" Enter option : ";
					std::cin >> op;
					std::cout <<"-------------------------------"<< std::endl;
					
					if(op == 5) break;
					
					switch(op){
						case 1 : usr.search_acc();	break;
						case 2 : usr.check_balance();	break;
						case 3 : usr.send_money();	break;
						case 4 : usr.deposit_money();	break;
						default: std::cout <<" wrong option! Enter again\n";
					}
				}
				break;
			case 3 : 
				 std::cout <<"-------------------------------"<< std::endl;
				 std::cout <<"         | THANK YOU |         "<< std::endl;
				 std::cout <<"-------------------------------"<< std::endl;
				 exit(0);
			default: std::cout <<" wrong option! Enter again!\n";
		}
	}
}
