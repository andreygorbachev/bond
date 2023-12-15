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

#pragma once

#include <chrono>
#include <memory>


namespace security
{

	template<double nominal = 100.0> class bond
	{

	public:

		explicit bond(
			std::chrono::year_month_day maturity,
			double coupon
		) noexcept;

	public:

		auto get_nominal() const noexcept -> double;

		auto get_maturity() const noexcept -> std::chrono::year_month_day;
		auto get_coupon() const noexcept -> double;

	private:

		std::chrono::year_month_day _maturity;
		double _coupon;

	};


	template<double nominal> bond<nominal>::bond(
		std::chrono::year_month_day maturity,
		double coupon
	) noexcept :
		_maturity{ std::move(maturity) },
		_coupon{ coupon }
	{
	}


	template<double nominal> auto bond<nominal>::get_nominal() const noexcept -> double
	{
		return nominal;
	}


	template<double nominal> auto bond<nominal>::get_maturity() const noexcept -> std::chrono::year_month_day
	{
		return _maturity;
	}

	template<double nominal> auto bond<nominal>::get_coupon() const noexcept -> double
	{
		return _coupon;
	}

}
