#include "crectlib.h"
#include "crectlib.cpp"
#include <iostream>
using namespace std;

int firstH( int x, int y, int x1, int y1 ){
    int b = y, e = y1, m;
    while( b != e ){
        m = ( b + e ) / 2;
        if( rect( x, y, x1, m ) )
            e = m;
        else
            b = m + 1;
    }
    return b;
}

int firstV( int x, int y, int x1, int y1 ){
    int b = x, e = x1, m;
    while( b != e ){
        m = ( b + e ) / 2;
        if( rect( x, y, m, y1 ) )
            e = m;
        else
            b = m + 1;
    }
    return b;
}

int lastH( int x, int y, int x1, int y1 ){
    int b = y, e = y1, m;
    while( b != e ){
        m = (b + e) / 2 + 1;
        if( rect( x, m, x1, y1 ) )
            b = m;
        else
            e = m - 1;
    }
    return b;
}

int lastV( int x, int y, int x1, int y1 ){
    int b = x, e = x1, m;
    while( b != e ){
        m = (b + e) / 2 + 1;
        if( rect( m, y, x1, y1 ) )
            b = m;
        else
            e = m - 1;
    }
    return b;
}

int main(){
    int n = gridsize();
    int R, C, R1, C1;
    int a, b, c, d;
    int r1, c1;

    R = firstV( 1, 1, n, n );
    C = firstH( 1, 1, n, n );
    R1 = lastV( 1, 1, n, n );
    C1 = lastH( 1, 1, n, n );
    //cout << R << " " << C << " " << R1 << " " << C1 << "\n";

    //Aquí está el monstruo
    if( rect( R, C, R, C ) ){
        //cout << "estamos en el monstruo\n";
        if( rect( R + 1, C, R + 1, C) ){

            c1 = C;
            c = R;
            d = lastV( R, C, R1 - 1, C );
            if( d == R1 - 1 && rect( R1, C, R1, C ) )
                d = R1;

            if( d < R1 ){
                r1 = R1;
                a = firstH( r1, C, r1, C1 );
                b = lastH( r1, C, r1, C1 );
            } else {
                if( rect( R, C + 1, R1, C + 1 ) ){
                    a = C;
                    b = lastH( R, C, R1, C1 - 1 );
                    if( b == C1 - 1 )
                        b++;
                } else{
                    a = firstH( R, C + 1, R1, C1 );
                    b = C1;
                }
                r1 = max( firstV( 1, a, n, a ), firstV( 1, b, n, b ) );
            }

        } else {

            r1 = R;
            a = C;
            b = lastH( R, C, R, C1 - 1 );
            if( b == C1 - 1 && rect( R, C1, R, C1 ) )
                b = C1;

            if( b < C1 ){
                c1 = C1;
                c = firstV( R, c1, R1, c1 );
                d = lastV( R, c1, R1, c1 );
            } else {
                 if( rect( R + 1, C, R + 1, C1 ) ){
                    c = R;
                    d = lastV( R, C, R1 - 1, C1 );
                    if( d == R1 - 1 )
                        d++;
                } else {
                    c = firstV( R + 1, C, R1, C1 );
                    d = R1;
                }
                c1 = max( firstH( c, 1, c, n ), firstH( d, 1, d, n ) );
            }

        }

        report( r1, a, r1, b, c, c1, d, c1 );
        return 0;

    }

    if( rect( R, C1, R, C1 ) ){
        //cout << "estamos en el segundo monstruo\n";
        if( rect( R + 1, C1, R + 1, C1 ) ){

            c1 = C1;
            c = R;
            d = lastV( R, C1, R1 - 1, C1 );
            if( d == R1 - 1 && rect( R1, C1, R1, C1 ) )
                d = R1;
            //cout << c << " " << d << " " << c1 << "\n";

            if( d < R1 ){
                r1 = R1;
                a = firstH( r1, C, r1, C1 );
                b = lastH( r1, C, r1, C1 );
            } else {
                if( rect( R, C + 1, R1, C + 1 ) ){
                    a = C;
                    b = lastH( R, C, R1, C1 - 1 );
                    if( b == C1 - 1 )
                        b++;
                } else{
                    a = firstH( R, C + 1, R1, C1 );
                    b = C1;
                }
                r1 = max( firstV( 1, a, n, a ), firstV( 1, b, n, b ) );
            }

        } else {

            //cout << "aun más profundo en el monstruo\n";
            r1 = R;
            a = firstH( R, C + 1, R, C1 );
            b = C1;
            if( a == C + 1 && rect( R, C, R, C ) )
                a = C;

            if( a > C ){
                c1 = C;
                c = firstV( R, c1, R1, c1 );
                d = lastV( R, c1, R1, c1 );
            } else {
                 if( rect( R + 1, C, R + 1, C1 ) ){
                    c = R;
                    d = lastV( R, C, R1 - 1, C1 );
                    if( d == R1 - 1 )
                        d++;
                } else {
                    c = firstV( R + 1, C, R1, C1 );
                    d = R1;
                }
                c1 = max( firstH( c, 1, c, n ), firstH( d, 1, d, n ) );
            }

        }

        report( r1, a, r1, b, c, c1, d, c1 );
        return 0;
    }
    //Aquí termina el monstruo

    if( rect( R, C + 1, R1, C + 1 ) ){
        a = C;
        b = lastH( R, C, R1, C1 );
    } else{
        a = firstH( R, C + 1, R1, C1 );
        b = C1;
    }
    r1 = max( firstV( 1, a, n, a ), firstV( 1, b, n, b ) );

    if( rect( R + 1, C, R + 1, C1 ) ){
        c = R;
        d = lastV( R, C, R1, C1 );
    } else {
        c = firstV( R + 1, C, R1, C1 );
        d = R1;
    }

    //cout << a << " " << b << " " << c << " " << d << "\n";

    r1 = max( firstV( 1, a, n, a ), firstV( 1, b, n, b ) );
    c1 = max( firstH( c, 1, c, n ), firstH( d, 1, d, n ) );
    //cout << r1 << " " << c1 << "\n";

    report( r1, a, r1, b, c, c1, d, c1 );

}
