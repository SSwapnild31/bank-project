#include<iostream>
#include<cstring>
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
		private:
			std::string m_user, m_pass;
		public:	
			bool login_admin(){
				std::string user, pass;

				auto read_lambda = [](std::string &u, std::string &p){
					std::cout <<" Enter Username : ";
					getline(std::cin, u);
				
					std::cout <<" Enter Password : ";
					getline(std::cin,p);
				};

				std::ifstream file("pass.dat");
				
				//If file doesn't exit -> create it
				if(!file){
					std::cout <<"-------------------------------\n";
					
					std::cout <<" Set username & password\n";
					
					read_lambda(m_user, m_pass);
					
					std::ofstream("pass.dat") << m_user << "\n" << m_pass;
					
					std::cout <<" Details saved successfully\n\n";
					std::cout <<" Enter Admin details to login\n";
					std::cout <<"-------------------------------\n";
				}
				
				file.close();

				//Read from file
				std::ifstream f1("pass.dat");
				
				getline(f1, m_user);
				getline(f1, m_pass);
				
				f1.close();
				
				read_lambda(user, pass);
				
				return (m_user == user  && m_pass == pass);
			}

			void write_data(bank_column bc){
				std::ofstream file("record.dat",std::ios::binary | std::ios::app);
				
				if(!file){
					std::cout <<" Error : opening file\n";
					return;
				}

				file.write((char*)&bc, sizeof(bc));
				
				file.close();
			}
			
			bank_column read_data(){
				bank_column bc{};
				
				std::ifstream file("record.dat",std::ios::binary);

				if(!file){
					std::cout <<" File not present\n";
					return bc; 
				}

				if(file.read((char*)&bc, sizeof(bc))){
					std::cout <<" Error reading file\n";
					return bank_column{};
				}

				file.close();
				return bc;
			}
			
			void create_acc() {
				std::cout <<" Creating Account\n";
				bank_column acc;
				
				acc.acc_no = record_count() + 1;
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
				
				std::ifstream file("record.dat",std::ios::binary);
				
				if(!file){
					std::cout <<" Error : reading file\n";
					return;
				}

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
				
				std::ifstream file("record.dat",std::ios::binary);

				if(!file){
					std::cout <<" Error in opening file/not present\n";
					return;
				}

				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Acc Balance ->\n";
						std::cout <<" .............................\n";
						std::cout <<" Acc number  : "<< bc.acc_no << std::endl;
						std::cout <<" Acc balance : "<< bc.balance <<" ₹."<< std::endl;
						
						file.close();
						return;
					}
				}
				
				std::cout <<" Acc not present/wrong number!\n";
			}
			
			void display_records() {	
				bank_column bc;
				
				std::ifstream file("record.dat",std::ios::binary);
				
				if(!file){
					std::cout <<" Error in opening file/not present\n";
					return;
				}
				
				std::cout <<" All Records : \n";	
				while( file.read((char*)&bc,sizeof(bc)) ){
					display(bc);
				}
				
				file.close();
			}

			int record_count(){
				
				int count = 0;
				bank_column bc;

				std::ifstream file("record.dat",std::ios::binary);					
				while(file.read((char*)&bc,sizeof(bc))){
					count++;
				}
				file.close();

				return count;
			}

			void display(bank_column bc){
				std::cout <<" .............................\n";	
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
				
				std::ifstream file("record.dat",std::ios::binary);
				
				if(!file){
					std::cout <<"Error: opening file/not present\n";
					return;
				}

				while(file.read((char*)&bc, sizeof(bc))){
					if(bc.acc_no == acn){
						std::cout <<" Acc Balance ->\n";
						std::cout <<" .............................\n";
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
				
				std::ifstream file("record.dat",std::ios::binary);

				if(!file){
					std::cout <<"Error: opening file/not present\n";
					return;
				}

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
				std::cout <<" .............................\n";
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

	std::cout <<"-------------------------------\n";
	std::cout <<"          | WELCOME |          \n";
	std::cout <<"-------------------------------\n";


	while(true){	
		int ch, attempt = 0;
		std::cout <<"    1.Admin  2.User  3.Exit\n";
		std::cout <<"-------------------------------\n";
		std::cout <<" Enter option : ";
		std::cin >> ch;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//To remove extra remaining \n

		switch(ch){
			case 1 :
				login :
					if(attempt == 2){
						std::cout <<" Warning: Last attempt remaining!\n";
						std::cout <<"-------------------------------\n";
					}
					if(adm.login_admin()){
						
						std::cout <<"-------------------------------\n";
						std::cout <<"           Logged In           \n";
						
						while(true){
							
							int op, c;
							std::cout <<"-------------------------------\n";
							std::cout <<" 1.Create Acc\t2.Update Acc\n 3.Search Acc\t4.Delete Acc\n 5.Check bal\t6.Display Accs\n 7.Count Accs\t8.Main menu\n";
							std::cout <<"-------------------------------\n";
							std::cout <<" Enter option : ";
							std::cin >> op;
							std::cout <<"-------------------------------\n";

							if(op == 8) break;

							switch(op){
								case 1 : adm.create_acc();		break;
								case 2 : adm.update_acc();		break;
								case 3 : adm.search_acc();		break;
								case 4 : adm.delete_acc();		break;
								case 5 : adm.check_balance();	break;
								case 6 : adm.display_records();	break;
								case 7 : c = adm.record_count();
										 std::cout <<" Total records : "<< c << std::endl;	break;
								default: std::cout <<" wrong option! Enter again!\n";
							}
						}	
					}
					else{
						std::cout <<" wrong username/password!\n\n";
						attempt++;
						if(attempt < 3)	goto login;

						std::cout <<"-------------------------------\n";
						std::cout <<" Access blocked : \n"; 
						std::cout <<"     Too many failed attempts! \n";
						std::cout <<"-------------------------------\n";
						return 1;
					}
				break;
			case 2 :
				while(true){
					int op;
					std::cout <<"-------------------------------\n";
					std::cout <<" 1.Search Acc\t2.Check bal\n 3.Send money\t4.Deposit money\n 5.Main menu\n";
					std::cout <<"-------------------------------\n";
					std::cout <<" Enter option : ";
					std::cin >> op;
					std::cout <<"-------------------------------\n";
					
					if(op == 5) break;
					
					switch(op){
						case 1 : usr.search_acc();		break;
						case 2 : usr.check_balance();	break;
						case 3 : usr.send_money();		break;
						case 4 : usr.deposit_money();	break;
						default: std::cout <<" wrong option! Enter again\n";
					}
				}
				break;
			case 3 : 
				 std::cout <<"-------------------------------\n";
				 std::cout <<"         | THANK YOU |         \n";
				 std::cout <<"-------------------------------\n";
				 exit(0);
			default: std::cout <<" wrong option! Enter again!\n";
		}
	}
	
	return 0;
}