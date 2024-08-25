# include <stdio.h>
# include <ctype.h>

int main (){
    int alphabetArray[26] ={0};
    char letter;

printf("Enter text here, then enter EOF when finished, then hit CTRL + D to get results: \n");

while ((letter = getchar()) !=EOF){
    if(isalpha(letter)){
        letter = tolower(letter);
        alphabetArray[letter-'a']++;
    }
}


printf("Frequency of letters in line \n");
for (int i=0; i<26; i++) {
    printf("%c: %d\n", 'a' + i, alphabetArray[i]);
}


return 0;
}
