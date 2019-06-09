#include <stdio.h>
#include <string.h>
#define N 5200

char a[N], b[N];
int na, nb, l[N][N], r[N][N], u[128];

int main() {
    int i, j, ans, lcs;
    scanf("%s%s", a, b);
    na=strlen(a);
    nb=strlen(b);
    for(i=0; i<=na; i++) l[i][0]=r[i][nb]=0;
    for(i=0; i<=nb; i++) l[0][i]=r[na][i]=0;
    for(i=1; i<=na; i++) for(j=1; j<=nb; j++) {
        if(a[i-1]==b[j-1]) l[i][j]=l[i-1][j-1]+1;
        else if(l[i-1][j]>l[i][j-1]) l[i][j]=l[i-1][j];
        else l[i][j]=l[i][j-1];
    }
    for(i=na-1; i>=0; i--) for(j=nb-1; j>=0; j--) {
        if(a[i]==b[j]) r[i][j]=r[i+1][j+1]+1;
        else if(r[i+1][j]>r[i][j+1]) r[i][j]=r[i+1][j];
        else r[i][j]=r[i][j+1];
    }
    ans=0; 
    lcs=l[na][nb];    
    for(i=0; i<128; i++) u[i]=-1;
    for(i=0; i<=na; i++) for(j=0; j<nb; j++) if(u[(int)b[j]]<i) {
        if(l[i][j]+r[i][j+1]+1>lcs) {
            u[(int)b[j]]=i;
            ans++;    
        }
    }
    printf("%d\n", ans);
    return 0;
}