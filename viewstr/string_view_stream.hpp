#ifndef __STRING_VIEW_STREAM
#define __STRING_VIEW_STREAM 1

#include <streambuf>
#include <string_view>
#include <istream>

namespace viewstr
{
	template <class ChT, class Traits = std::char_traits<ChT>>
	class basic_string_view_stream : public std::basic_istream<ChT, Traits>
	{
		class basic_view_buf : public std::basic_streambuf<ChT, Traits>
		{
			using int_type = typename Traits::int_type;
			using char_type = typename Traits::char_type;
		public:
			basic_view_buf(const std::basic_string_view<ChT, Traits> view_)
			{
				ChT* chbeg = const_cast<ChT*>(view_.data());
				ChT* chend = const_cast<ChT*>(view_.data() + view_.size());
				this->setg(chbeg, chbeg, chend);
				this->setp(chend, chend);
			}
		private:
			// read: no override needed
			// write: we are const
			std::streamsize xsputn(const char_type*, std::streamsize) override
			{
				return 0;
			}
			int_type overflow(int_type) override
			{
				return Traits::eof();
			}
			int sync() override
			{
				return -1;
			}
			int_type pbackfail(int_type)
			{
				return Traits::eof();
			}
		};

		basic_view_buf _buf;
	public:
		explicit basic_string_view_stream(const std::basic_string_view<ChT, Traits> view_)
			: std::basic_istream<ChT, Traits>{ &_buf }
			, _buf{ view_ }
		{}
	};

	using string_view_stream = basic_string_view_stream<char>;
	using wstring_view_stream = basic_string_view_stream<wchar_t>;
}

#endif
