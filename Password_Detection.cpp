#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <string.h>
char geneSet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!1234567890";
char  target[]="ActiveAI123";
char* generate_parent(int length)
	{
		
		char* gene;
		gene= (char*) calloc(length, sizeof(char));
		for (int i=0; i<length; i++)
		{
		int RandIndex = rand() % strlen(geneSet);		
		gene[i]=geneSet[RandIndex];
		}
		gene[length]='\0';
		return (gene);
	}	


int get_fitness(char guess[])
	{ int sum=0;
		for(int i=0; i<strlen(target); i++)
		{
			if(guess[i]==target[i])
			{
				sum++;
			}
		}
	return(sum);
	}

void mutate(char parent[])
	{  
       int RandIndex = rand() % strlen(parent);
       int RandIndex_1 = rand() % strlen(geneSet);
       parent[RandIndex]=geneSet[RandIndex_1];
       
	}

int main()
{
	srand (time(NULL));
	int i, j;
	char *bestParent = generate_parent(strlen(target)) ;
	int bestFitness = get_fitness(bestParent);
	
	
	char* child =(char*) calloc(strlen(target), sizeof(char));
	int c=0;
	while (1)
	{
		strcpy(child,bestParent);    
		mutate(child);
    	int childFitness = get_fitness(child);
	c++;
	cout<<"Generation_"<<c<<"    "<<child<<endl;
    if (bestFitness >= childFitness)
    	{ 
    		continue;
    	}
    
     bestFitness = childFitness;
	strcpy(bestParent,child);
	
	if (bestFitness >= strlen(target))
    	{ 
    	break;
    	} 

	}
	

}

