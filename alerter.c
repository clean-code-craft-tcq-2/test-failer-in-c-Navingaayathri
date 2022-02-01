#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
	if(celcius >200)
		return 500;
	else
      return 200;
    }
float convertFarenheitToCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit,float (*fpconvertFarenheitToCelcius)(float),int (*fpnetworkAlertStub)(float)) {
    float celcius = fpconvertFarenheitToCelcius(farenheit);
    int returnCode = fpnetworkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5,&convertFarenheitToCelcius,&networkAlertStub);
	float returnValue = convertFarenheitToCelcius(400.5);
	assert((int)returnValue == 204);
	assert(alertFailureCount == 1);
    alertInCelcius(303.6,&convertFarenheitToCelcius,&networkAlertStub);
	returnValue = convertFarenheitToCelcius(303.6);
	assert((int)returnValue == 150);
	assert(alertFailureCount == 1);
	alertInCelcius(500,&convertFarenheitToCelcius,&networkAlertStub);
	returnValue = convertFarenheitToCelcius(500);
	assert(returnValue == 260);
	assert(alertFailureCount == 2);
	alertInCelcius(620,&convertFarenheitToCelcius,&networkAlertStub);
	returnValue = convertFarenheitToCelcius(620);
	assert(alertFailureCount == 3);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (Yes it is! :> )\n");
    return 0;
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(600);
    alertInCelcius(620);
    assert(alertFailureCount == 3);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
