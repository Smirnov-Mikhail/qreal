#pragma once

#include "abstractRecognizer.h"
#include "geometricForms.h"

namespace qReal {
namespace gestures {

class RectangleGesturesManager : public GesturesRecognizer<qreal *>
{
public:
	RectangleGesturesManager();
	~RectangleGesturesManager();
	qreal getMaxDistance(const QString &);
	bool isMultistroke();
	qreal getDistance(qreal * const &key1, qreal * const &key2);
	qreal *getKey(const PathVector & path);
};

}
}
