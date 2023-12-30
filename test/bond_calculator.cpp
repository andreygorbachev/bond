// The MIT License (MIT)
//
// Copyright (c) 2023 Andrey Gorbachev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <bond_calculator.h>
#include <utils.h>

#include <gtest/gtest.h>

#include <chrono>


using namespace std;
using namespace std::chrono;


namespace security
{

	TEST(bond_calculator, constructor)
	{
		const auto bc = bond_calculator{
			2024y / April / 1d,
			0.025
		};

		EXPECT_EQ(0.025, bc.get_coupon());
	}


	auto make_bond_calculator() noexcept -> bond_calculator<100.0>
	{
		return bond_calculator{
			2024y / April / 1d,
			from_percent(2.5)
		};
	}

	TEST(bond_calculator, get_nominal)
	{
		const auto bc = make_bond_calculator();

		EXPECT_EQ(100.0, bc.get_nominal());
	}

	TEST(bond_calculator, get_maturity)
	{
		const auto bc = make_bond_calculator();

		EXPECT_EQ(2024y / April / 1d, bc.get_maturity());
	}

	TEST(bond_calculator, get_coupon)
	{
		const auto bc = make_bond_calculator();

		EXPECT_EQ(0.025, bc.get_coupon());
	}

}
