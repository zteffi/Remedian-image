#include <vector>
#include <opencv2/core.hpp>

struct RemedianImage {
	
	size_t _base;
	std::vector<std::vector<cv::Mat>> remedian;
	std::vector<size_t> count_base;
	size_t count = 0;

public:
	RemedianImage::RemedianImage(size_t base = 11):
	_base(base)
	{
		remedian.push_back(std::vector<cv::Mat>(base+1));
		count_base.push_back(0);
	}

	size_t Update(cv::Mat m) {
		for (auto i = 0; i < remedian.size(); i++) {
			if (i + 1 == remedian.size()) {
				remedian.push_back(std::vector<cv::Mat>(_base+1));
				count_base.push_back(0);
			}
			remedian[i][count_base[i]] = m;
			count_base[i]++;
			if (count_base[i] > _base) {
				m = Median(remedian[i].begin(), remedian[i].end());
				count_base[i] = 0;
			}
			else {
				remedian[i][count_base[i]] = m;
				break;
			}

		}
		return ++count;
	}


	cv::Mat GetRemedian() {
		if (count == 0) {
			return cv::Mat();
		}
		size_t idx = count_base.size() - 1;
		while (count_base[idx] == 0)
			idx--;
		return Median(remedian[idx].begin(), remedian[idx].begin() + count_base[idx] + 1);
	}

private:
	cv::Mat Median(decltype(remedian[0].begin()) begin_it, decltype(remedian[0].end()) end_it) {
		cv::Mat tmp;
		// We will sorting pixels where the first mat will get the lowest pixels and the last one, the highest
		size_t count = 0;;
		for (auto it = begin_it; it < end_it; it++) {
			for (auto jt = it + 1; jt < end_it; jt++) {
				it->copyTo(tmp);
				min(*it, *jt, *it);
				max(*jt, tmp, *jt);
			}
			++count;
		}
		auto med = count / 2;
		if (!(med % 2)) {
			// TODO handle median for even numbers configurably
			med++;
		}
		return *(begin_it + med);
	}
};