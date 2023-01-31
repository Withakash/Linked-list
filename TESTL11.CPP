#include"list11.cpp"
void main()
{
  list l;
  int choice,pos,n,b;
  item_type item,given;
  clrscr();
   puts("Want to create list");
   puts("1. YES\n2. NO");
   scanf("%d",&b);
   if(b==1)
   {
    puts("Enter Number of element insert");
    scanf("%d",&n);
    printf("Enter %d element",n);
    for(int i=0;i<n;i++)
    {
     scanf("%d",&item);
     l.insertlast(item);
    }
   }
  while(1)
  {
     clrscr();
     puts("1. INSERT FIRST");
     puts("2. INSERT LAST");
     puts("3. INSERT AFTER GIVEN");
     puts("4. INSERT BEFORE GIVEN");
     puts("5. INSERT AT POSITION");
     puts("6. INSERT AT SORTED");
     puts("7. DISPLAY");
     puts("8. SIZE");
     puts("9. DELETE FIRST");
     puts("10. DELETE LAST");
     puts("11. DELETE GIVEN");
     puts("12. DELETE AFTER GIVEN");
     puts("13. DELETE BEFORE GIVEN");
     puts("14. DELETE AT POSITION");
     puts("15. DELETE LARGEST");
     puts("16. DELETE SMALLEST");
     puts("17. FIND MAXIMUM");
     puts("18. FIND MINIMUM");
     puts("19. REVERSE");
     puts("20. EXIT");
     puts("Enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
	  printf("Enter item: ");
	  scanf("%d",&item);
	  l.insertfirst(item);
	  break;
       case 2:
	  printf("Enter item: ");
	  scanf("%d",&item);
	  l.insertlast(item);
	  break;
       case 3:
	  printf("Enter item: ");
	  scanf("%d",&item);
	  printf("Enter given item: ");
	  scanf("%d",&given);
	  l.insertaftergiven(item,given);
	  break;
       case 4:
	  printf("Enter item: ");
	  scanf("%d",&item);
	  printf("Enter given item: ");
	  scanf("%d",&given);
	  l.insertbeforegiven(item,given);
	  break;
       case 5:
	 printf("Enter item: ");
	 scanf("%d",&item);
	 printf("Enter Postion: ");
	 scanf("%d",&pos);
	 l.inseratgivenposition(item,pos);
	 break;
       case 6:
	  printf("Enter item: ");
	  scanf("%d",&item);
	  l.insertinsortedlist(item);
	  break;
       case 7:
	  l.display();
	  break;
       case 8:
	  printf("There are %d item Available",l.size());
	  break;
       case 9:
	  printf("%d element deleted from first",l.deletefirst());
	  break;
       case 10:
	  printf("%d element delted from last",l.deletelast());
	  break;
       case 11:
	  puts("Enter Given item");
	  scanf("%d",&given);
	  printf("%d element deleted",l.deletegiven(given));
	  break;
       case 12:
	  puts("Enter Given item");
	  scanf("%d",&given);
	  printf("%d element deleted",l.deleteaftergiven(given));
	  break;
       case 13:
	  puts("Enter Given item");
	  scanf("%d",&given);
	  printf("%d element deleted",l.deletebeforegiven(given));
	  break;
       case 14:
	  puts("Enter position");
	  scanf("%d",&pos);
	//  printf("%d element deleted",l.deleteatgivenposition(pos));
	  break;
       case 15:
	//  printf("Largest item %d deleted",l.deletelargest());
	  break;
       case 16:
	//  printf("Smallest item %d deleted",l.deletesmallest());
	  break;
       case 17:
	//  printf("%d is largest element",l.findmax());
	  break;
       case 18:
	 // printf("%d is Smallest element",l.findmin());
	  break;
       case 19:
	  //reverse();
	  break;
       case 20:
	  return;
       default:
	 puts("Invalid Choice");
	 break;
     }
     getch();
  }
}