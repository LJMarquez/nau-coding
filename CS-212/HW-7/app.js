console.log("Hello World!");

downloadResumeButton = document.getElementById("download-resume-btn");
nameHeader = document.getElementById("name-header");
deadlineDateElement = document.getElementById("stock-trader-deadline-date");
deadlineDaysLeftElement = document.getElementById("stock-trader-deadline-days-left");

const name = "Leo";
const deadline = "2028-05-13";

let hasDownloadedResume = false;

downloadResumeButton.addEventListener("click", function () {
    if (!hasDownloadedResume) {
        hasDownloadedResume = true;
        setTimeout(function () {
            alert("Your resume is downloaded successfully!");
        }, 2000);
    }
});

function showGreeting(name) {
    currentDate = new Date();
    currentHour = currentDate.getHours();
    let greeting;
    if (currentHour > 4 && currentHour < 13) {
        greeting = "Good Morning";
    }
    else if (currentHour > 12 && currentHour < 18) {
        greeting = "Good Afternoon";
    }
    else {
        greeting = "Good Evening";
    }
    nameHeader.innerHTML = greeting + ", my name is " + name + "! Welcome to my portfolio!";
}

document.addEventListener("DOMContentLoaded", function () {
    showGreeting(name);
});

function daysUntilDeadline(deadline) {
    let currentDate = new Date();
    let deadlineDate = new Date(deadline);
    let timeDifference = deadlineDate - currentDate;
    let daysDifference = timeDifference / (1000 * 3600 * 24);
    return Math.round(daysDifference);
}

let numberOfDaysUntilDeadline = daysUntilDeadline(deadline);

deadlineDateElement.innerHTML += deadline;
deadlineDaysLeftElement.innerHTML += numberOfDaysUntilDeadline;