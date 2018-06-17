#ifndef CTREESET_H
#define CTREESET_H

#include <iostream>


#define MIN(a, b) (((a) <= (b))? (a) : (b))
#define MAX(a, b) (((a) >= (b))? (a) : (b))

#define TREE_DEEP(tree) ((tree)? (tree) -> lenght() : 0)
#define TREE_SIZE(tree) ((tree)? (tree) -> abs() : 0)
#define MAX_TREE(a, b) ((TREE_DEEP(a) >= TREE_DEEP(b))? a : b)
#define MIN_TREE(a, b) ((TREE_DEEP(a) >= TREE_DEEP(b))? b : a)
#define TREE_END(tree) ((tree)? (tree) -> end() : 0)
#define COPY_TREE(tree) ((tree)? new CTreeSet<CItem>(*(tree)) : NULL)

template <typename CItem>
struct CTreeSet {
private:
    CTreeSet<CItem> *Left, *Right;
    CItem *Root;

    int Crr, Flag; // FLAG показывает какой элемент надо обойти правый левиы или вернуть корень CRR вернуть глубину дерева


public:
    CTreeSet();
    CTreeSet(const CItem& val);
    CTreeSet(const CTreeSet<CItem>& M);
    ~CTreeSet();

    int isEmpty(void) const {return (Root)? 0 : 1;}
    CTreeSet<CItem>& makeEmpty(void);

    CTreeSet<CItem>& add(const CItem& val);
    CTreeSet<CItem>& del(const CItem& val);
    CTreeSet<CItem>& makeBalanced(void);
    int contains(const CItem& val) const;

    int abs(void) const;
    int lenght(void) const;


    CItem begin(void);
    CItem forward(void);
    int end(void) const {return Crr;}

    CTreeSet<CItem>& operator=(const CTreeSet<CItem>& M);

};

template <typename CItem>
CTreeSet<CItem>::CTreeSet() {
    Root = NULL;
    Left = NULL;
    Right = NULL;

    Crr = 0;
    Flag = 1;
}

template <typename CItem>
CTreeSet<CItem>::CTreeSet(const CItem& val) {
    Root = new CItem(val);
    Left = NULL;
    Right = NULL;

    Crr = 1;
    Flag = 1;
}

template <typename CItem>
CTreeSet<CItem>::CTreeSet(const CTreeSet<CItem>& M) {
    if ( M.Root )
        Root = new CItem(*M.Root);
    else
        Root = NULL;

    if ( M.Right )
        Right = new CTreeSet<CItem>(*M.Right);
    else
        Right = NULL;

    if ( M.Left )
        Left = new CTreeSet<CItem>(*M.Left);
    else
        Left = NULL;
}

template <typename CItem>
CTreeSet<CItem>::~CTreeSet() {
    delete Left;
    delete Root;
    delete Right;
}

template <typename CItem>
CTreeSet<CItem>& CTreeSet<CItem>::makeEmpty(void) {
    delete Root;
    delete Left;
    delete Right;

    Root = NULL;
    Left = NULL;
    Right = NULL;

    Crr = 0;
    Flag = 1;

    return *this;
}

template <typename CItem>
CTreeSet<CItem>& CTreeSet<CItem>::add(const CItem& val) {

    if ( !Root )
        Root = new CItem(val);
    else if ( val > *Root ) {
        if ( !Right )
            Right = new CTreeSet<CItem>(val);
        else if ( val != *Right -> Root && !Left ) {
            Left = new CTreeSet<CItem>(*Root);

            if ( val < *Right -> Root )
                *Root = val;
            else {
                *Root = *Right -> Root;
                *Right -> Root = val;
            }
        } else
            Right -> add(val);
    } else if ( val < *Root ) {
        if ( !Left )
            Left = new CTreeSet<CItem>(val);
        else if ( val != *Left -> Root && !Right ) {
            Right = new CTreeSet<CItem>(*Root);

            if ( val > *Left -> Root )
                *Root = val;
            else {
                *Root = *Left -> Root;
                *Left -> Root = val;
            }
        } else
            Left -> add(val);
    }

    return this -> makeBalanced();
}

template <typename CItem>
CTreeSet<CItem>& CTreeSet<CItem>::del(const CItem& val) {
    if ( Root ) {

        if ( val > *Root ) {
            if ( Right )
                Right -> del(val);
        } else if ( val < *Root ) {
            if ( Left )
                Left -> del(val);
        } else if ( Right && Right -> lenght() >= TREE_DEEP(Left) ) {
            *Root = *Right -> Root;
            Right -> del(*Root);

            if ( !Right -> Root ) {
                delete Right;
                Right = NULL;
            }
        } else if ( Left && Left -> lenght() > TREE_DEEP(Right)) {
            *Root = *Left -> Root;
            Left -> del(*Root);

            if ( !Left -> Root ) {
                delete Left;
                Left = NULL;
            }
        } else {
            delete Root;
            Root = NULL;
        }
    }

    return *this;
}

template <typename CItem>
CTreeSet<CItem>& CTreeSet<CItem>::makeBalanced(void) {

    if ( Root ) {
        if( Right )
            Right -> makeBalanced();

        if ( Left )
            Left -> makeBalanced();

        if ( TREE_DEEP(Right) - TREE_DEEP(Left) > 1 ) {
            CTreeSet<CItem> *tmp = new CTreeSet<CItem>;

            tmp -> Root = Root;
            tmp -> Left = Left;
            tmp -> Right = Right -> Left;
            Left = tmp;

            tmp = Right -> Right;
            Root = Right -> Root;

            Right -> Left = NULL;
            Right -> Root = NULL;
            Right -> Right = NULL;

            delete Right;
            Right = tmp;
        } else if ( TREE_DEEP(Left) - TREE_DEEP(Right) > 1 ) {
            CTreeSet<CItem> *tmp = new CTreeSet<CItem>;

            tmp -> Root = Root;
            tmp -> Right = Right;
            tmp -> Left = Left -> Right;
            Right = tmp;

            tmp = Left -> Left;
            Root = Left -> Root;

            Left -> Left = NULL;
            Left -> Root = NULL;
            Left -> Right = NULL;

            delete Left;
            Left = tmp;
        }
    }

    return *this;
}

template <typename CItem>
int CTreeSet<CItem>::contains(const CItem& val) const {
    int res = 0;

    if ( Root ) {
        if ( val > *Root ) {
            if ( Right )
                res = Right -> contains(val);
        } else if ( val < *Root ) {
            if ( Left )
                res = Left -> contains(val);
        } else
            res = 1;
    }

    return res;
}

template <typename CItem>
int CTreeSet<CItem>::abs(void) const {
    int res = (Root)? 1 : 0;

    if ( Left )
        res += Left -> abs();

    if ( Right )
        res += Right -> abs();

    return res;
}

template <typename CItem>
int CTreeSet<CItem>::lenght(void) const {
    return ((Root)? 1 : 0) + MAX(TREE_DEEP(Right), TREE_DEEP(Left));
}


template <typename CItem>
CItem CTreeSet<CItem>::begin(void) {
    CItem res;

    Crr = this -> abs();
    Flag = 1;

    if ( Root )
        res = *Root;

    if ( Left ) {
        res = Left -> begin();
        Flag = -1;
    }

    return res;
}

template <typename CItem>
CItem CTreeSet<CItem>::forward(void) {
    CItem res;
    int flip = 1;

    if ( Flag < 0 ) {
        res = Left -> forward();
        Flag = -Left -> end();
    }

    if ( Flag == 0 ) {
        res = *Root;
        Flag = 1;
        flip = 0;
    }

    if ( flip && Flag >= 1 && Right ) {
        if ( Flag == 1 ) {
            res = Right -> begin();
            Flag = 2;
        } else
            res = Right -> forward();
    }

    Crr--;

    return res;
}

template <typename CItem>
CTreeSet<CItem>& CTreeSet<CItem>::operator=(const CTreeSet<CItem>& M) {
    if ( &M != this ) {
        delete Left;
        delete Root;
        delete Right;

        if ( M.Root )
            Root = new CItem(*M.Root);
        else
            Root = NULL;

        if ( M.Right )
            Right = new CTreeSet<CItem>(*M.Right);
        else
            Right = NULL;

        if ( M.Left )
            Left = new CTreeSet<CItem>(*M.Left);
        else
            Left = NULL;
    }

    return *this;
}


template <typename CItem>
std::istream& operator>>(std::istream& input, CTreeSet<CItem>& M) {
    int num;
    CItem tmp;

    input >> num;

    for(; num > 0; num--) {
        input >> tmp;
        M.add(tmp);
    }

    return input;
}

template <typename CItem>
std::ostream& operator<<(std::ostream& output, const CTreeSet<CItem>& M) {
    if ( M.isEmpty() )
        output << "Empty set";
    else {
        CTreeSet<CItem> copy(M);
        CItem tmp;
        char flag = 1;


        output << '{';

        for(tmp = copy.begin(); copy.end(); tmp = copy.forward()) {
            if ( flag )
                flag = 0;
            else
                output << ", ";

            output << tmp;
        }

        output << '}';
    }

    return output;
}

#undef TREE_END
#undef TREE_SIZE
#undef MIN_TREE
#undef MAX_TREE
#undef COPY_TREE
#undef TREE_DEEP

#undef MIN
#undef MAX

#endif
