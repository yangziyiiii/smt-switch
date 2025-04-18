/*********************                                                        */
/*! \file test-bv.cpp
** \verbatim
** Top contributors (to current version):
**  Yoni Zohar 
** This file is part of the smt-switch project.
** Copyright (c) 2020 by the authors listed in the file AUTHORS
** in the top-level source directory) and their institutional affiliations.
** All rights reserved.  See the file LICENSE in the top-level source
** directory for licensing information.\endverbatim
**
** \brief Tests for theory of bit-vectors.
**
**
**/

// #include <utility>
// #include <vector>

// #include "available_solvers.h"
// #include "gtest/gtest.h"
// #include "smt.h"

// using namespace smt;
// using namespace std;

// namespace smt_tests {

// GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(BVTests);
// class BVTests : public ::testing::Test,
//                  public ::testing::WithParamInterface<SolverConfiguration>
// {
//  protected:
//   void SetUp() override
//   {
//     s = create_solver(GetParam());
//     s->set_opt("produce-models", "true");
//     s->set_opt("incremental", "true");
//   }
//   SmtSolver s;
// };

// // based on issue #308
// TEST_P(BVTests, to_int)
// {
//   Sort sort1 = s->make_sort(BV, 1);
//   Sort sort2 = s->make_sort(BV, 2);
//   Term x1 = s->make_symbol("x1", sort1);
//   Term x2 = s->make_symbol("x2", sort2);
//   s->check_sat();
//   uint64_t i1 = s->get_value(x1)->to_int();
//   uint64_t i2 = s->get_value(x2)->to_int();
//   ASSERT_TRUE(0 <= i1 && i1 <= 1);
//   ASSERT_TRUE(0 <= i2 && i2 <= 3);

// }

// INSTANTIATE_TEST_SUITE_P(
//     ParameterizedSolverBVTests,
//     BVTests,
//     testing::ValuesIn(filter_solver_configurations({ THEORY_BV })));

// }  // namespace smt_tests

#include <iostream>
#include <memory>
#include <vector>
#include "assert.h"

#include "bitwuzla_factory.h"
#include "smt.h"
// after a full installation
// #include "smt-switch/boolector_factory.h"
// #include "smt-switch/smt.h"

using namespace smt;
using namespace std;

int main()
{
  SmtSolver s = BitwuzlaSolverFactory::create(false);
  s->set_logic("QF_ABV");
  s->set_opt("produce-models", "true");
  Sort bvsort8 = s->make_sort(BV, 8);
  Term x = s->make_symbol("x", bvsort8);
  Term y = s->make_symbol("y", bvsort8);
  Term xpy = s->make_term(BVAdd, x, y);

  for (auto c : xpy)
  {
    assert(c == x || c == y);
  }

  return 0;
}
