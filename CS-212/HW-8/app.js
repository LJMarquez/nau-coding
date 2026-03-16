console.log("Hello World!");

let downloadResumeButton = document.getElementById("download-resume-btn");
let nameHeader = document.getElementById("name-header");
let deadlineDateElement = document.getElementById("stock-trader-deadline-date");
let deadlineDaysLeftElement = document.getElementById("stock-trader-deadline-days-left");
let projectsContainer = document.getElementById("projects-container");
let resumeDownloadCountElement = document.getElementById("resume-download-count");

const name = "Leo";
let resumeDownloadCount = 0;

let projectTitles = ["Edumon", "Culinary Showdown", "Stock Trader"];
let projectImages = ["edumon.png", "culinary-showdown.png", "stock-trading.jpeg"];
let projectDescriptions = ["A full-stack turn-based RPG built with React Native where players collect and battle monsters by answering educational questions.", "A typing/adventure game built using HTML, CSS, and JavaScript with audio and interactivity.", "Work in progress."];
let projectDeadlines = ["2024-08-19", "2023-11-08", "2028-05-13"];

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
    let currentDate = new Date();
    let currentHour = currentDate.getHours();
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

let skillsForm = document.getElementById("add-skill-form");

skillsForm.addEventListener("submit", function (event) {
    event.preventDefault();
    let skillInput = document.getElementById("new-skill-input");
    let skill = skillInput.value;
    if (skill) {
        let skillsList = document.getElementById("other-skills-list");
        let newSkillItem = document.createElement("li");
        newSkillItem.textContent = skill;
        newSkillItem.classList.add("list-group-item");
        skillsList.appendChild(newSkillItem);
        skillInput.value = "";
    }
});

for (let i = 0; i < projectTitles.length; i++) {
    let title = projectTitles[i];
    let imageSrc = projectImages[i]
    let description = projectDescriptions[i];
    let deadline = projectDeadlines[i];

    let containerDiv = document.createElement("div");

    let card = document.createElement("div");
    card.classList.add("card", "h-100", "shadow-sm")

    let image = document.createElement("img");
    image.src = imageSrc;
    image.classList.add("card-img-top");

    let cardBody = document.createElement("div");
    cardBody.classList.add("card-body");

    let titleElement = document.createElement("h3");
    titleElement.innerText = title;
    titleElement.classList.add("h5", "card-title")

    let descriptionElement = document.createElement("p");
    descriptionElement.innerText = description;
    descriptionElement.classList.add("card-text", "mb-0");

    let deadlineElement = document.createElement("p");
    deadlineElement.innerText = "Deadline: " + deadline;
    deadlineElement.classList.add("card=text", "mb-0");

    let currentDate = new Date();
    let deadlineDate = new Date(deadline);
    let currentStateElement = document.createElement("p");
    currentStateElement.classList.add("card=text", "mb-0");
    if (currentDate > deadlineDate) {
        currentStateElement.innerText = "Current state: Completed";
        currentStateElement.style.color = "green";
    } else {
        currentStateElement.innerText = "Current state: Ongoing";
        currentStateElement.style.color = "red";
    }

    projectsContainer.appendChild(containerDiv);
    containerDiv.appendChild(card);
    card.appendChild(image);
    card.appendChild(cardBody);
    cardBody.appendChild(titleElement);
    cardBody.appendChild(descriptionElement);
    cardBody.appendChild(deadlineElement);
    cardBody.appendChild(currentStateElement);
}

function addResumeDownloadCount() {
    resumeDownloadCount++;
    resumeDownloadCountElement.innerText = resumeDownloadCount;
}

let educationTableContainer = document.getElementById("education-table-container");
let experienceTableContainer = document.getElementById("experience-table-container");

let educationTableHeaders = ["School Name", "Degree", "Graduation Year"];
let educationTableData = [
    ["Northern Arizona University", "B.A. in Computer Science, Minor in Cybersecurity", "2029"],
    ["West-MEC Central Campus", "Certificate in Application Development & JavaScript", "2025"]
];

let experienceTableHeaders = ["Organization", "Position", "Duration"];
let experienceTableData = [
    ["NAU Information Technology Services", "Information Security Services Student Employee", "2025 - Present"],
    ["Agua Fria High School District", "Graphic Design Intern", "2024 - 2025"]
];

let educationTable = document.createElement("table");
educationTable.classList.add("table", "table-striped", "table-hover", "align-middle");
let educationTableHead = document.createElement("thead");
educationTableHead.classList.add("table-dark");
let educationHeaderRow = document.createElement("tr");
for (let i = 0; i < educationTableHeaders.length; i++) {
    let header = document.createElement("th");
    header.innerText = educationTableHeaders[i];
    educationHeaderRow.appendChild(header);
}
educationTableHead.appendChild(educationHeaderRow);
educationTable.appendChild(educationTableHead);

let educationTableBody = document.createElement("tbody");

for (let i = 0; i < educationTableData.length; i++) {
    let row = document.createElement("tr");
    for (let j = 0; j < educationTableData[i].length; j++) {
        let cell = document.createElement("td");
        cell.innerText = educationTableData[i][j];
        row.appendChild(cell);
    }
    educationTableBody.appendChild(row);
}

educationTable.appendChild(educationTableBody);
educationTableContainer.appendChild(educationTable);



let experienceTable = document.createElement("table");
experienceTable.classList.add("table", "table-striped", "table-hover", "align-middle");
let experienceTableHead = document.createElement("thead");
experienceTableHead.classList.add("table-dark");
let experienceHeaderRow = document.createElement("tr");
for (let i = 0; i < experienceTableHeaders.length; i++) {
    let header = document.createElement("th");
    header.innerText = experienceTableHeaders[i];
    experienceHeaderRow.appendChild(header);
}
experienceTableHead.appendChild(experienceHeaderRow);
experienceTable.appendChild(experienceTableHead);

let experienceTableBody = document.createElement("tbody");

for (let i = 0; i < experienceTableData.length; i++) {
    let row = document.createElement("tr");
    for (let j = 0; j < experienceTableData[i].length; j++) {
        let cell = document.createElement("td");
        cell.innerText = experienceTableData[i][j];
        row.appendChild(cell);
    }
    experienceTableBody.appendChild(row);
}

experienceTable.appendChild(experienceTableBody);
experienceTableContainer.appendChild(experienceTable);