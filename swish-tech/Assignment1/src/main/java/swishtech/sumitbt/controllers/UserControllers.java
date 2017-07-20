package swishtech.sumitbt.controllers;

import java.util.UUID;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import swishtech.sumitbt.models.EmailConfirmationToken;
import swishtech.sumitbt.models.PasswordResetToken;
import swishtech.sumitbt.models.Role;
import swishtech.sumitbt.models.User;
import swishtech.sumitbt.repositories.EmailConfirmationTokenRepo;
import swishtech.sumitbt.repositories.PasswordResetTokenRepo;
import swishtech.sumitbt.repositories.RoleRepo;
import swishtech.sumitbt.repositories.UserRepo;
import swishtech.sumitbt.services.MailService;

@RestController
public class UserControllers
{
	@Autowired
	private UserRepo userRepo;
	
	@Autowired
	private RoleRepo roleRepo;
	
	@Autowired
	private EmailConfirmationTokenRepo emailConfirmationRepo;
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	@Autowired
	private MailService ms;
	
	@ResponseBody
	@RequestMapping(value="/user",method=RequestMethod.POST)
	public String create(@RequestBody User user)
	{
		String username,email,password;
		username=user.getUsername();
		email=user.getEmail();
		password=user.getPassword();
		if(username.equals(null))
			return "username cannot be null";
		else if(email.equals(null))
			return "email cannot be null";
		else if(password.equals(null))
			return "password cannot be null";
		else if(userRepo.findByUsername(username)!=null)
			return "user with username = "+username+" already exist";
		else if(userRepo.findByEmail(email)!=null)
			return "user with email = "+email+" already exist";
		Role userRole = roleRepo.findByRolename("User");
		if(userRole==null)
		{
			return "roles table might not been initialized";
		}
		user.setRole(userRole);
		user.setEnabled(false);
		User user2;
		try
		{
			user2 = userRepo.save(user);
		}catch(Exception e)
		{
			return "Exception occured while saving user\n Details:\n"+e.toString();
		}
		EmailConfirmationToken ect = new EmailConfirmationToken(UUID.randomUUID().toString(), user2.getId());
		ect.setConfirmed(false);
		try
		{
			emailConfirmationRepo.save(ect);
		}catch(Exception e)
		{
			userRepo.delete(user);
			return "Exception occured while creating email confirmation token\n Details:\n"+e.toString();
		}
		try
		{
			ms.sendEmailConfirmationMail(user2);
		}catch(Exception e)
		{
			emailConfirmationRepo.delete(ect);
			userRepo.delete(user);
			return "Exception occured while sending email confirmation link\n Details:\n"+e.toString();
		}
		return "Check your mail : "+user.getEmail();
	}
	
	@ResponseBody
	@RequestMapping(value="/user/forgotpassword",method=RequestMethod.POST)
	public String reset(@RequestBody User user)
	{
		User user2 = userRepo.findByEmail(user.getEmail());
		if(user2!=null)
		{
			PasswordResetToken prt = new PasswordResetToken(UUID.randomUUID().toString(), user2.getId());
			prt.setConfirmed(false);
			try
			{
				passwordResetTokenRepo.save(prt);
			}catch(Exception e)
			{
				return "Exception occured while creating password reset token\n Details:\n"+e.toString();
			}
			try
			{
				ms.sendPasswordResetMail(user2);
			}catch(Exception e)
			{
				passwordResetTokenRepo.delete(prt);
				return "Exception occured while sending password reset link\n Details:\n"+e.toString();
			}
			return "Check your mail : "+user.getEmail();
		}
		else
		{
			return "email does not exist ";
		}
	}
	
}
