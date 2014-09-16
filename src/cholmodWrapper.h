/***************************************************************************
 *   Copyright (C) 2007-2014 by the resistivity.net development team       *
 *   Carsten Rücker carsten@resistivity.net                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _GIMLI_CHOLMODWRAPPER__H
#define _GIMLI_CHOLMODWRAPPER__H

#include "gimli.h"
#include "solverWrapper.h"

namespace GIMLI{

class DLLEXPORT CHOLMODWrapper : public SolverWrapper {
public:
    CHOLMODWrapper(RSparseMatrix & S, bool verbose = false);
    
    CHOLMODWrapper(CSparseMatrix & S, bool verbose = false);
    
    virtual ~CHOLMODWrapper();

    static bool valid();

    int factorise();
    
    virtual int solve(const RVector & rhs, RVector & solution);
    
    virtual int solve(const CVector & rhs, CVector & solution);

protected:
    int initialize_(RSparseMatrix & S);
    
    int initialize_(CSparseMatrix & S);

    void *c_;
    void *A_;
    void *L_;
};

} //namespace GIMLI;

#endif // _GIMLI_CHOLMODWRAPPER__H
