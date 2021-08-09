#include <iostream>


using namespace std;
// employee's information
struct node {
	
	string first;
	string last;
	int id;
	int hours;
	struct node *next;
	
};

struct node *front = 0;
struct node *rear;

bool program = false;

void create();//creates the program
void add();//adds a node filled with employee's data
void remove();//deletes information of an employee
void modify();//Searches the id and Modifys the information of the employee
void display();//Searches and display's one employee's info
void display_all();//displays all employee's information



int main(int argc, char** argv) {
	
	int option = -1;//user selection
	int num; // variable

	
	while (option != 0){
	//menu-------------------------------------------------------------
	cout << "----------Menu----------" << endl <<endl ;
	cout << "1: Create database" << endl;
	cout << "2: Add employee info" << endl;
	cout << "3: Remove employee's info" << endl;
	cout << "4: Search a employee's info" << endl;
	cout << "5: Display all employee's info'" << endl;
	cout << "6: Modify employee's info'" << endl;
	cout << "0: Exit the program" << endl << endl;
	cout << "------------------------"<< endl << endl;
	cout << "Selection: ";
	cin >> option;
	
	switch(option){
		case 1:
			create();
			break;
			
		case 2:
			add();
			break;
			
		case 3:
			remove();
			break;
		
		case 4:
			display();
			break;
			
		case 5:
			display_all();
			break;
		
		case 6:
			modify();
			break;
			
		case 0:
			system("cls");
			
			cout << "-----Program closing-----" << endl << endl;
			cout << "Have a good day and stay safe" << endl;
			
			break;
		default:
			system("cls");
			cout << "Invalid Please Try Again." << endl;
			cout << "Selection: ";
			cin >> option; 
			
		
	}
	

	
}
	
	
	return 0;
}


void create(){
	
	system("cls");
	
	if(program == false){
		
		program = true;
		
		cout << "Program has been created" << endl;
	}
	else 
		cout << "Program has already been created" << endl;
	
	
}

void add(){
	
	system("cls");
	
	
	struct node *t = new node;
	struct node *temp = new node;
	struct node *temp1 = new node;
	temp = front;
	temp1 = front;
	int num;
	int exit = 0;
	int stop = 0;
	bool ID_EXISTS = false;
	
	
	
	
	
	if (program == false)
		cout << "Program is not created" << endl;
		
	else{
	
		cout << "Enter the employee's ID #: " << endl;
		cin >> t->id;
// checks if there already is an ID#
//--------------------------------------------------------------------
		if (front==NULL)
			ID_EXISTS = false;
		else if (temp1->id == t->id )
			ID_EXISTS = true;
		else{
		
			while (stop != 1){
				
				if (temp1->id== t->id){
				
					ID_EXISTS = true;
					stop = 1;
				}
				else if (temp1->next == 0)
					stop = 1;
				else
					temp1 = temp1->next;
			}
		}
		
//------------------------------------------------------------------------
		
		if (ID_EXISTS == true)
		cout << "Employee ID#: " << t->id << " already exists." << endl;
		else{
		
		
			
			
			cout << "Enter the employee's first name: ";
			cin >> t->first;
			cout << "Enter the employee's last name: ";
			cin >> t->last;
			cout << "Enter the amount of hours they worked this week: ";
			cin >> t->hours;
			
			t->next = 0;
			if (front==NULL){
				front = t;
				
			}
			else if(t->id < front->id){
				
				t->next = front;
				front = t;
					
			}
			else if(t->id > front->id && (front->next==0)){
				front->next = t;
				
			}
			else if(t->id >front->id){
				
				while(exit!=1){
					
					if (temp->next->id > t->id && t->id > temp->id){
						
						t->next = temp->next;
						temp->next = t;
						exit = 1;
					}
					else{
						temp= temp->next;
					}
					if (temp->next == 0){
					temp->next = t;
					t->next = 0;
					exit = 1;
					}
					
				}
				
				
			}
			
			
		}
			
	}
		
		
}

void remove(){
	
	
	system("cls");
	int ID;
	int stop = 0;
	int validation;
	int i=0;
	bool exists = false;
	
	
	if(program ==false)
		cout << "Program is not created" << endl;
	else if(front ==NULL)
		cout << "Database is empty" << endl;
	else{
	
		cout << "--Removing--" << endl;
		cout << "Enter employee's ID#: ";
		cin >> ID;
		
		node *t = new node();
		
		t=front;
		
		if (t->id == ID )
		exists = true;
		
		else{
		
			while (stop != 1){
				
				if (t->id==ID){
				
					exists = true;
					stop =1;
				}
				else if (t->next == 0)
					stop = 1;
				else
					t = t->next;
			}
		}
		
		if (exists == true){
		
		
			cout << "Are you sure you want to remove employee #" << ID << "'s information?" << endl;
			cout << "0: No" << endl;
			cout << "1: Yes" << endl << endl;
			
			cout << "Selection: ";
			cin >> validation;
			
			while ( i !=1){
			
				
				
				if (validation == 1 || validation == 0){
					i=1;
					stop = 0;
				
				}
				else{
					cout << "Invalid Please Try Again: ";
					cin >> validation;
					
				}
					
			
			}
			
			if(validation==1){
					
					node *temp = new node;
					node *hold = new node;
					
					temp = front;
					hold = temp->next;
					
					while (stop != 1){
						if (hold->id == ID){
					
							temp->next = hold->next;
							delete hold;
						
							stop = 1;
							
						}
						
						else if (temp->id == ID){
							front = front->next;
							delete (temp);
							stop = 1;
						}
						
						
						else{
						
						temp = temp->next;
						hold = hold->next; 
						}
					}
				
			}
			else if(validation == 0)
				cout << "Employee #" << ID << " was not removed." << endl;
			
		}
		else
			cout << "ID# " << ID << " does not exist" << endl;	
	}
	
}

void modify(){
	
	system("cls");
	int ID;
	int stop=0;
	bool exists = false;
	
	if(program ==false)
		cout << "Program is not created" << endl;
	else if(front ==NULL)
		cout << "Database is empty" << endl;
	else{
	
	cout << "---Modifying Employee's Information--- " << endl << endl;
	cout << "Enter the employee's ID#:";
	cin >> ID;
	
	node *t = new node();
	t= front;
		
		if (t->id == ID )
		exists = true;
		
		else{
		
			while (stop != 1){
				
				if (t->id==ID){
				
					exists = true;
					stop =1;
				}
				else if (t->next == 0)
					stop = 1;
				else
					t = t->next;
			}
		}
		
		
		
		if (exists == true){
		stop = 0;
		
		
			while (stop!=1){
				
				if (t->id==ID){
					system("cls");
					int choice;
					
					cout << "What would you like to modify?" << endl;
					cout << "1:Name" << endl;
					cout << "2:Hours" << endl;
					cout << "0:Exit" << endl;
					cout << "Selection: ";
					cin >> choice;
					
					bool repeat = true;
					
					while (repeat == true){
					
						switch (choice){
							case 1:
								cout << "Enter the first name of the employee: ";
								cin >> t->first;
								cout << "Enter the last name of the employee: ";
								cin >> t->last;	
								repeat = false;	
								break;
								
							case 2:
								cout << "Enter the new amount of hours worked: ";
								cin >> t->hours;
								repeat = false;
								break;
								
							case 0:
								stop = 1;
								repeat = false;
								break;
								
							default:
								cout << "Invalid response try again." << endl; 
								cout << "Selection: ";
								cin >> choice;
								break;
							
						}
					}
					
				}
				
				else
					t= t->next;
				
			}
			
			
		}
		else 
			cout << "ID# " << ID << " does not exist" << endl;
	
	}
	
}

void display(){
	
	system("cls");
	
	int ID;
	int stop=0;
	bool exists =false;
	
	if(program ==false)
		cout << "Program is not created" << endl;
	else if(front ==NULL)
		cout << "Database is empty" << endl;
	else{
	
		cout << "---Display---" << endl;
		cout << "Enter employee's ID#: ";
		cin >> ID;
		
		node *t = new node();
		t= front;
		
		if (t->id == ID )
		exists = true;
		else{
		
			while (stop != 1){
				
				if (t->id==ID){
				
					exists = true;
					stop =1;
				}
				else if (t->next == 0)
					stop = 1;
				else
					t = t->next;
			}
		}
		if (exists == true){
				
				cout << "First\t Last\t\t ID#\t Hours worked" << endl;
				cout << "-----\t ----\t\t ---\t ------------" << endl;
				cout << t->first << "\t " << t->last << "\t\t "<< t->id << "\t " << t->hours << endl << endl;
				
			
			}
			
			
		
		else
			cout << "ID# " << ID << " does not exist" << endl;
		
	}
	
}

void display_all(){
	
	system("cls");
	int num=0;
	int exit=0;
	
	if(program ==false)
		cout << "Program is not created" << endl;
	else if(front ==NULL)
		cout << "Database is empty" << endl;
	
	else{
		cout << "------Employee's Data------" << endl << endl;
		
		node *t = new node;
		t = front;
		
		
		
		cout << "First\t Last\t\t ID#\t Hours worked" << endl;
		cout << "-----\t ----\t\t ---\t ------------" << endl;
		while (exit!=1){
			
			if (t->next != 0){
				cout << t->first << "\t " << t->last << "\t\t " << t->id << "\t " << t->hours << endl << endl;
				t=t->next;
			}
			else{
			
			cout << t->first << "\t " << t->last << "\t\t " << t->id << "\t " << t->hours << endl << endl;
			exit = 1;
			}
		}
		
	
	}
}

















