#include <java.security.jgss.test.h>

#include <java.security.jgss.h>
#include <java.base.h>
#include <java.logging.h>
#include <java.naming.h>
#include <java.security.sasl.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$security$jgss$test$PreloadClass(void* eventData) {
}

void java$security$jgss$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$security$jgss$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$setCurrentObjectStack();
	}
}

$StringArray* java$security$jgss$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$security$jgss$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$security$jgss$test$GetResource($String* name) {
	return nullptr;
}

void java$security$jgss$test::init() {
	::java$security$jgss::init();
	::java$base::init();
	::java$logging::init();
	::java$naming::init();
	::java$security$sasl::init();
	::java::lang::Library lib = {
		"java.security.jgss.test", "17.35", "",
		nullptr,
		java$security$jgss$test$LibEventAction,
		java$security$jgss$test$GetPackages,
		java$security$jgss$test$GetClassEntry,
		java$security$jgss$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}