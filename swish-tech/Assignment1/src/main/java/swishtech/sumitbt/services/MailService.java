package swishtech.sumitbt.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.MailException;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;
import swishtech.sumitbt.models.User;
import swishtech.sumitbt.repositories.EmailConfirmationTokenRepo;
import swishtech.sumitbt.repositories.PasswordResetTokenRepo;

@Service
public class MailService
{
	@Autowired
	private EmailConfirmationTokenRepo emailConfirmationRepo; 
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	private JavaMailSender jms;
	@Autowired
	public MailService(JavaMailSender jms)
	{
		this.jms = jms;
	}
	public void sendEmailConfirmationMail(User user) throws MailException
	{
		SimpleMailMessage mail = new SimpleMailMessage();
		mail.setTo(user.getEmail());
		mail.setFrom("");
		mail.setSubject("Email Confirmation");
		mail.setText("Click the below link to confirm\n"+"http://localhost:8080/confirm/"+emailConfirmationRepo.findByUserId(user.getId()).getToken());
		jms.send(mail);
	}
	
	public void sendPasswordResetMail(User user) throws MailException
	{
		SimpleMailMessage mail = new SimpleMailMessage();
		mail.setTo(user.getEmail());
		mail.setFrom("");
		mail.setSubject("Password Reset");
		mail.setText("Click the below link to reset\n"+"http://localhost:8080/reset/"+passwordResetTokenRepo.findByUserId(user.getId()).getToken());
		jms.send(mail);
	}
	
}
