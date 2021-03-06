#include<iostream>

using namespace std;

typedef struct node
{
	int data;	// will store information
	node *next;	// the reference to the next node
};


int main()
{
	node *head = NULL;	//empty linked list
	int info = 0, node_number = 0,  counter = 0;
	char ch;

	do{
		cout<<"\n\n";
		cout<<"0.Quit\n";
		cout<<"1.Insert at first\n";
		cout<<"2.Traverse\n";
		cout<<"3.Insert at last\n";
		cout<<"4.Insert after specified number of node\n";
		cout<<"5.Delete at first node\n";
		cout<<"6.Delete at last node\n";
		cout<<"7.Delete specified number of node\n";
		cout<<"8.Sort nodes\n";

		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{

			case '0': break;

			case '1':{
						cout<<"ENTER ANY NUMBER:";
						cin>>info;						// take input data
					  	cout<<"Input data: "<<info<<"  Node No: "<<++counter;
						node *temp;							// create a temporary node
						temp = (node*)malloc(sizeof(node));	// allocate space for node
						temp->data = info;					// store data(first field)
						temp->next=head;					// store the address of the pointer head(second field)
						head = temp;						// transfer the address of 'temp' to 'head'
						break;
					}


			case '2':{
						node *temp1;							// create a temporary node
						temp1 = head;						// transfer the address of 'head' to 'temp'
						if(temp1 == NULL)
						{
							cout<<endl<<"The linked list is empty"<<endl;
							break;
						}
						else
						{
							cout<<"Linked list: ";
							while( temp1!=NULL )
							{
								cout<< temp1->data<<" ";			// show the data in the linked list
								temp1 = temp1->next;				// tranfer the address of 'temp->next' to 'temp'
							}

							cout<<endl<<"Number of nodes: "<<counter<<endl;
							break;
						}
					 }


			case '3':{
						 // check linked list is empty
						if(head==NULL)
						{
							cout<<"ENTER ANY NUMBER:";
							cin>>info;						// take input data
					  		cout<<"Input data: "<<info;

							node *temp;						// create a temporary node
							temp = (node*)malloc(sizeof(node));	// allocate space for node
							temp->data = info;				// store data(first field)
							temp->next = NULL;				// second field will be null
							head = temp;					// transfer the address of 'temp' to 'head'
							counter++;
						}

						else
						{
							cout<<"ENTER ANY NUMBER:";
							cin>>info;						// take input data
					  		cout<<"Input data: "<<info;
							node *temp1;						// create a temporary node
							temp1=(node*)malloc(sizeof(node));	// allocate space for node
							temp1 = head;					// transfer the address of 'head' to 'temp'
							while(temp1->next!=NULL)			// go to the last node
								temp1 = temp1->next;			//tranfer the address of 'temp->next' to 'temp'

							node *temp;					// create a temporary node
							temp = (node*)malloc(sizeof(node));// allocate space for node
							temp->data = info;				// store data(first field)
							temp->next = NULL;				// second field will be null(last node)
							temp1->next = temp;				// 'temp' node will be the last node
							break;
						}
					}


			case '4':{
						// check linked list is empty
						if(head==NULL)
						{
							cout<<"The Linked List is empty"<<endl;
							break;
						}

						cout<<"ENTER ANY NUMBER:";
						cin>>info;						    // take input data
					  	cout<<"Input data: "<<info<<endl;

						cout<<"ENTER THE NODE NUMBER:";
						cin>>node_number;						// take the node number from user

						node *temp1;							// create a temporary node
						temp1 = (node*)malloc(sizeof(node));	// allocate space for node
						temp1 = head;


						for( int i = 1 ; i < node_number ; i++ )
						{
							temp1 = temp1->next;				// go to the next node

							if( temp1 == NULL )
							{
								cout<<node_number<<" node is not exist"<< endl;
								break;
							}
						}

						 node *temp;						    // create a temporary node
						 temp = (node*)malloc(sizeof(node));	// allocate space for node
						 temp->data = info;					// store data(first field)
						 temp->next = temp1->next;			//transfer the address of temp1->next to temp->next
						 temp1->next = temp;				//transfer the address of temp to temp1->next
						 counter++;
						 break;
					}


			case '5':{
							// check linked list is empty
						if(head==NULL)
						{
							cout<<"The Linked List is empty"<<endl;
							break;
						}
						else	// check linked list has only one node
							if(head->next==NULL)
							{
								head = NULL;
								cout<<"The first node of the Linked List is deleted"<<endl;
								cout<<"The Linked List is empty"<<endl;
								counter--;
								break;
							}

						node *temp;							// create a temporary node
						temp = (node*)malloc(sizeof(node));	// allocate space for node
						temp = head;						// transfer the address of 'head' to 'temp'
						head = temp->next;					// transfer the address of 'temp->next' to 'head'
						free(temp);
						cout<<"The first node of the Linked List is deleted"<<endl;
						counter--;
						break;
					}

		   case '6':{
						// check linked list is empty
						if(head==NULL)
						{
							cout<<"The Linked List is empty"<<endl;
							break;
						}
						else	// check linked list has only one node
							if(head->next==NULL)
							{
								head = NULL;
								cout<<"The last node of the Linked List is deleted"<<endl;
								cout<<"The Linked List is empty"<<endl;
								counter--;
								break;
							}


						node *temp1;							// create a temporary node
						temp1 = (node*)malloc(sizeof(node));	// allocate space for node
						temp1 = head;							//transfer the address of head to temp1

						node *old_temp;							// create a temporary node
						old_temp = (node*)malloc(sizeof(node));	// allocate space for node

						while(temp1->next!=NULL)			// go to the last node
						{
							old_temp = temp1;			// transfer the address of 'temp1' to 'old_temp'
							temp1 = temp1->next;			// transfer the address of 'temp1->next' to 'temp1'
						}

						old_temp->next = NULL;			// previous node of the last node is null

						free(temp1);
						cout<<"The last node of the Linked List is deleted"<<endl;
						counter--;
						break;
					}


		 case '7':{
							// Check if link list is empty
						if(head==NULL)
						{
							cout<<"The Linked List is empty"<<endl;
							break;
						}
						else	// check linked list has only one node
							if(head->next==NULL)
							{
								head = NULL;
								cout<<"The last node of the Linked List is deleted"<<endl;
								cout<<"The Linked List is empty"<<endl;
								counter--;
								break;
							}

						cout<<"ENTER THE NODE NUMBER:";
						cin>>node_number;						// take location

							// Check if node is exist
						if(node_number > counter)
						{
							cout<<"No such node is exist";
							break;
						}

						node *temp1;							// create a temporary node
						temp1 = (node*)malloc(sizeof(node));	// allocate space for node
						temp1 = head;						// transfer the address of 'head' to 'temp1'

						node *old_temp;							// create a temporary node
						old_temp = (node*)malloc(sizeof(node));	// allocate space for node
						old_temp = temp1;						// transfer the address of 'temp1' to 'old_temp'

						// Check node number is 1
						if( node_number == 1 )
						{
							head = temp1->next;					// transfer the address of 'temp1->next' to 'head'
							free(temp1);
							counter--;
							cout<<node_number<<" node of the Linked List is deleted"<<endl;
							break;
						}

							// Go to the node number of the node
						for( int i = 1 ; i < node_number ; i++ )
						{

							old_temp = temp1;				// store previous node
							temp1 = temp1->next;				// store current node

						}

						old_temp->next = temp1->next;		// transfer the address of 'temp1->next' to 'old_temp->next'
						free(temp1);

						counter--;
						cout<<node_number<<" node of the Linked List is deleted"<<endl;
						break;

					 }


		case'8':{
					node *temp1;							// create a temporary node
					temp1 = (node*)malloc(sizeof(node));	// allocate space for node

					node *temp2;							// create a temporary node
					temp2 = (node*)malloc(sizeof(node));	// allocate space for node

					int temp = 0;							// store temporary data value

					for( temp1 = head ; temp1!=NULL ; temp1 = temp1->next )
					{
						for( temp2 = temp1->next ; temp2!=NULL ; temp2 = temp2->next )
						{
							if( temp1->data > temp2->data )
							{
								temp = temp1->data;
								temp1->data = temp2->data;
								temp2->data = temp;
							 }
						 }
				   }

					cout<<"Nodes of the Linked List is sorted"<<endl;
					break;




				}

		}




	 }while(ch!='0');





	return 0;
}