/*********************                                                        */
/*! \file smt_defs.h
** \verbatim
** Top contributors (to current version):
**   Makai Mann, Clark Barrett
** This file is part of the smt-switch project.
** Copyright (c) 2020 by the authors listed in the file AUTHORS
** in the top-level source directory) and their institutional affiliations.
** All rights reserved.  See the file LICENSE in the top-level source
** directory for licensing information.\endverbatim
**
** \brief Type definitions for pointers to main abstract objects.
**
**
**/

// IWYU pragma: private, include "smt.h"

#pragma once

#include <memory>
#include <string>

namespace smt {

struct Op;

class AbsSort;
using Sort = std::shared_ptr<AbsSort>;

class AbsTerm;
using Term = std::shared_ptr<AbsTerm>;

class AbsSmtSolver;
using SmtSolver = std::shared_ptr<AbsSmtSolver>;

// Configurations for MathSat bit-vector interpolant method
namespace Configurations{
    // configuration export to the user
    struct MsatInterpolatorConfiguration {
    std::string interpolation_mode;
    /*
        -theory.bv.interpolation_mode=INT
            Interpolation technique to use for bit-vectors. Possible values are:
            - 0 : equality substitution + LA(Z) encoding  + bit-level 
            interpolation 
            - 1 : LA(Z) encoding + bit-level interpolation
            - 2 : bit-level interpolation only
            - 3 : LA(Z) encoding + equality substitution + bit-level interpolation
            - 4 : equality substitution + bit-level interpolation.
    */
    std::string eq_propagation;
    MsatInterpolatorConfiguration() : // default value
    interpolation_mode("0"), eq_propagation("false") {}
    };
} // name space configurations

// Datatype theory related
class AbsDatatypeDecl;
using DatatypeDecl = std::shared_ptr<AbsDatatypeDecl>;

class AbsDatatypeConstructorDecl;
using DatatypeConstructorDecl = std::shared_ptr<AbsDatatypeConstructorDecl>;

class AbsDatatype;
using Datatype = std::shared_ptr<AbsDatatype>;

}  // namespace smt
